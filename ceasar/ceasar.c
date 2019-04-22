#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// implement command line args
int main(int argc, string argv[])
{

  // Check for 2 arguments

  if (argc < 2)
  {
    printf("You must enter a command line argument\n");
    return 1;
  }

  //convert string to integer using: int key = atoi(num)
  int key = atoi(argv[1]);

  // intialize plaintext
  string text;
  // get text from user
  do
  {
    text = get_string("Enter your text to cipher: ");
  }
  // make sure the value is not empty
  while (strlen(text) < 1);
  printf("ciphertext: ");
  // 1. iterate through the string
  for (int i = 0, n = strlen(text); i < n; i++)
  {
    char letter = text[i];
    // 2. check for letter
    if (isalpha(letter))
    {
      // 2. check for upper
      if (isupper(letter))
      {
        printf("%c", ((letter - 'A') + key) % 26 + 'A');
      }
      // 2. else lower
      else
      {
        printf("%c", ((letter - 'a') + key) % 26 + 'a');
      }
    }
    else
    {
      printf("%c", letter);
    }
  }

  printf("\n");
}
