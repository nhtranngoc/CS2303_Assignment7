/** Program to demonstrate string reversal
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>

/** Print usage message
 */
void usage () {
  printf("usage: reversestring \"string with characters to reverse\"\n");
  printf("   OR: reversewords \"string with words to reverse\"\n");
}

/** Reverses all the characters in a string, in place.
 * For example, "hello world" becomes "dlrow olleh"
 * @param s String to reverse.
 */

void reversestring(char* s) {
  int i;
  int length = strlen(s);
  for(i=0;i<length/2;i++){
    char buf = s[i];
    s[i] = s[length-i-1];
    s[length-i-1]=buf;
  }
}

/** Reverses all the words in a string, in place.
 * For example, "hello world" becomes "world hello"
 * @param s String with words to reverse.
 */
void reversewords(char* s) {
  reversestring(s);
  char * pch=s;
  while (pch != NULL){
    pch = strtok(NULL, " ");
    if(pch != '\0'){
      char* buf = pch;
      reversestring(buf);
      strcat(s, buf);
      strcat(s, " ");
    }
  }
}

/** Must take exactly one argument.
 */
int main(int argc, char* argv[]) {

  char* command;  // duplicate of command name
  char* basec;    // basename of command
  char* s;       // String to reverse;
  int status;    // Set this to the return status of main()
  
  if (argc != 2) { // Check that it was called with exactly one argument
    usage();
    return 1;
  }

  s = strdup(argv[1]); // Sring to reverse

  // See how the command was invoked

  // First strip down to just the basename, no directory prefix
  command = strdup(argv[0]);
  basec = basename(command);

  // Which function we call depends on command name.
  if (strcmp(basec, "reversestring") == 0) {
    printf("Original string ----------> %s\n", s);
    reversestring(s);
    printf("Reversed complete string -> %s\n", s);
    status =  0;
  } else if (strcmp(basec, "reversewords") == 0) {
    printf("Original string ---------------> %s\n", s);
    reversewords(s);
    printf("Words in the string, reversed -> %s\n", s);
    status =  0;
  } else { // Those are the only two valid choices
    usage();
    status = 1;
  }


  // Free the duplicated strings
  free(s);
  free(command);
  return status;
}
