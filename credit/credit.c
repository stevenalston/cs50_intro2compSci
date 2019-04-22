// credit card validation

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
  // initialize variable
  long long ccNum;
  char cc[100];
  int digit, product, odds = 0, evens = 0;

  do
  {
    //  prompt user for cc number
    ccNum = get_long_long("Enter credit card number: ");

  }
  // check that the cc number is 13 to 16 numbers long
  while (ccNum < 0);

  sprintf(cc, "%lld", ccNum);
  // iterate through the string
  for (int i = 0, n = strlen(cc); i < n; i++)
  {
    if (strlen(cc) % 2 != 0)
    {
      // American Express uses 15-digit numbers
      if (i % 2 != 0)
      {
        product = (int)(cc[i] - 48) * 2;
        // check with product is a single digit
        while (product > 9)
        {
          digit = product % 10;
          product /= 10;
          odds += digit;
        }

        odds += product;
      }
      else
      {
        digit = (int)cc[i] - 48;
        evens = evens + digit;
      }
    }
    else
    {
      if (i % 2 == 0)
      {
        product = (int)(cc[i] - 48) * 2;
        // check with product is a single digit
        while (product > 9)
        {
          digit = product % 10;
          product /= 10;
          odds += digit;
        }

        odds += product;
      }
      else
      {
        digit = (int)cc[i] - 48;
        evens = evens + digit;
      }
    }
  }

  if ((evens + odds) % 10 == 0)
  {
    // American Express numbers all start with 34 or 37
    if ((cc[0] == '3' && (cc[1] == '4' || cc[1] == '7')) && strlen(cc) == 15)
    {
      printf("AMEX\n");
    }
    // MasterCard numbers start with 51, 52, 53, 54, or 55
    // MasterCard uses 16-digit numbers
    else if ((cc[0] == '5' && (cc[1] - 48 > 0 && cc[1] - 48 < 6)) && strlen(cc) == 16)
    {
      printf("MASTERCARD\n");
    }
    else if ((cc[0] == '4' && (strlen(cc) == 13 || strlen(cc) == 16)))
    {
      printf("VISA\n");
    }
    else
    {
      printf("INVALID\n");
    }
  }
  else
  {
    printf("INVALID\n");
  }
}