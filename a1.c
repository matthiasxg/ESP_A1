//-----------------------------------------------------------------------------
// a1.c
//
// Gross net tax calculator
//
// Group: 9
//
// Author: 12007662
//-----------------------------------------------------------------------------
//

#include <stdio.h>
#include <stdbool.h>

// forward declarations
int getGross();
bool getChildren();
double getSocialContribution(double gross);
double getIncomeTax(double gross);

//-----------------------------------------------------------------------------
///
/// The main program:
/// Calculates the gross net and prints the
/// result afterwards
///
/// @return always zero
//
int main()
{
  int gross = getGross();
  bool children = getChildren();
  double social_contribution = getSocialContribution(gross);
  double income_tax = getIncomeTax(gross - social_contribution);

  if (income_tax >= 100.0 && children)
  {
    income_tax -= 100.0;
  } else if (income_tax < 100.0 && children)
  {
    income_tax = 0.0;
  }

  printf("Brutto:\t\t%12.2f\n", (double) gross);
  printf("SV:\t\t%12.2f\n", social_contribution * -1.0);
  printf("LSt:\t\t%12.2f\n", income_tax * -1.0);
  printf("Netto:\t\t%12.2f\n", gross - social_contribution - income_tax);
  
  return 0;
}

//-----------------------------------------------------------------------------
///
/// Reads the gross from the console
///
/// @return user input: gross   
//
int getGross()
{
  int gross = 0.0;
  printf("Ihr monatliches Bruttoeinkommen: ");
  scanf("%d", &gross);

  while (gross <= 0 || gross > 5000000)
  {
    printf("Invalide Eingabe!\n");
    printf("Ihr monatliches Bruttoeinkommen: ");
    scanf("%d", &gross);
  }

  return gross;
}

//-----------------------------------------------------------------------------
///
/// Asks the user for children
///
/// @return bool children yes or no
//
bool getChildren()
{
  char input;
  bool children = false;

  scanf("%c", &input);
  printf("Kinder im Haushalt?: ");
  scanf("%c", &input);

  if (input == 'j' || input == 'J')
  {
    children = true;
  }
  else if (input == 'n' || input == 'N')
  {
    children = false;
  }
  else
  {
    printf("Invalide Eingabe!\n");
    scanf("%c", &input);
    children = getChildren();
  }
  
  scanf("%c", &input);
  return children;
}

//-----------------------------------------------------------------------------
///
/// Calculates the social contribution
///
/// @param gross
///
/// @return calculated social contribution
//
double getSocialContribution(double gross)
{
  double social_contribution = 0;
  unsigned short contribution_rate = 0;

  if (gross <= 5370)
  {
    if (gross <= 460)
    {
      contribution_rate = 0;
    }
    else if (gross <= 1733)
    {
      contribution_rate = 15;
    }
    else if (gross <= 1891)
    {
      contribution_rate = 16;
    }
    else if (gross <= 2049)
    {
      contribution_rate = 17;
    }
    else if (gross <= 5370)
    {
      contribution_rate = 18;
    }
    social_contribution = gross * (contribution_rate / 100.0);
  }
  else
  {
    social_contribution = 5370 * (18 / 100.0);
  }
  return social_contribution;
}

//-----------------------------------------------------------------------------
///
/// Calculates the income tax
///
/// @param gross without social contribution
///
/// @return calculated income tax
//
double getIncomeTax(double gross)
{
  double income_tax = 0.0;
  if (gross > 1000.0)
  {
    income_tax += 1000.0 * (0 / 100.0);
    gross -= 1000.0;
    if (gross > 500.0)
    {
      income_tax += 500.0 * (20 / 100.0);
      gross -= 500.0;
      if (gross > 1000.0)
      {
        income_tax += 1000.0 * (30 / 100.0);
        gross -= 1000.0;
        if (gross > 2500.0)
        {
          income_tax += 2500.0 * (40 / 100.0);
          gross -= 2500.0;
          if (gross > 0)
          {
            income_tax += gross * (50 / 100.0);
          }
        }
        else
        {
          income_tax += gross * (40 / 100.0);
        }
      }
      else
      {
        income_tax += gross * (30 / 100.0);
      }
    }
    else
    {
      income_tax += gross * (20 / 100.0);
    }
  }
  else
  {
    income_tax += gross * (0 / 100.0);
  }
  return income_tax;
}
