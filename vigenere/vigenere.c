#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// implement command line args
int main(int argc, string argv[])
{

  // Check for 2 arguments

  if (argc != 2)
  {
    printf("You must enter a string as a command line argument.\n");
    return 1;
  }

  // intialize the key
  string k = argv[1];
  char key;
  char letter;
  // declare the length of the key
  int len = strlen(k);

  // make sure key only contains letters
  for (int i = 0; i < len; i++)
  {
    if (!isalpha(k[i]))
    {
      printf("Key must be all letters\n");
      return 1;
    }
  }
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
  for (int i = 0, j = 0, n = strlen(text); i < n; i++)
  {
    letter = text[i];

    // check for letter
    if (isalpha(letter))
    {

      // check for upper
      if (isupper(letter))
      {
        key = toupper(k[j % len]);
        key -= 'A';
        printf("%c", ((letter - 'A') + key) % 26 + 'A');
      }

      if (islower(letter))
      {
        key = tolower(k[j % len]);
        key -= 'a';
        printf("%c", ((letter - 'a') + key) % 26 + 'a');
      }
      // increment j only if the plain text contains a letter
      j++;
    }
    else
    {
      printf("%c", letter);
    }
  }
  printf("\n");
}
