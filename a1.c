//-----------------------------------------------------------------------------
// a1.c
//
// Prints my student-ID
//
// Group: 9
//
// Author: 12007662
//-----------------------------------------------------------------------------
//

#include <stdio.h>
#include <stdbool.h>

// forward declarations
float getGross();
bool getChildren();
float getSocialContribution(float gross);
float getIncomeTax(float gross);

//-----------------------------------------------------------------------------
///
/// The main program
/// Prints my student-ID
///
/// @return always zero
//
int main()
{
  float gross = getGross();
  bool children = getChildren();
  float social_contribution = getSocialContribution(gross);
  float income_tax = getIncomeTax(gross - social_contribution);

  if (income_tax >= 100.0 && children)
  {
    income_tax -= 100.0;
  } else if (income_tax < 100.0 && children)
  {
    income_tax = 0.0;
  }

  printf("Brutto:\t\t%12.2f\n", gross);
  printf("SV:\t\t%12.2f\n", social_contribution * -1.0);
  printf("LSt:\t\t%12.2f\n", income_tax * -1.0);
  printf("Netto:\t\t%12.2f\n", gross - social_contribution - income_tax);
  
  return 0;
}

//-----------------------------------------------------------------------------
///
/// Gets the gross from the console
///
/// @return user input: gross
//
float getGross()
{
  float gross = 0;
  printf("Ihr monatliches Bruttoeinkommen: ");
  scanf("%f", &gross);

  while (gross <= 0 || gross > 5000000)
  {
    printf("Invalide Eingabe!\n");
    printf("Ihr monatliches Bruttoeinkommen: ");
    scanf("%f", &gross);
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
float getSocialContribution(float gross)
{
  float social_contribution = 0;
  if (gross <= 5370)
  {
    unsigned short contribution_rate = 0;
    if (461 <= gross && gross <= 1733)
    {
      contribution_rate = 15;
    }
    else if (1734 <= gross && gross <= 1891)
    {
      contribution_rate = 16;
    }
    else if (1892 <= gross && gross <= 2049)
    {
      contribution_rate = 17;
    }
    else if (2050 <= gross && gross <= 5370)
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
float getIncomeTax(float gross)
{
  float income_tax = 0.0;
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
