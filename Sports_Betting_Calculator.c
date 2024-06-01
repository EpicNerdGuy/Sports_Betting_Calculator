/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

// Function to calculate arbitrage opportunity
void calculate_arbitrage(double odds1, double odds2) {
    double arbitrage_opportunity = (1 / odds1) + (1 / odds2);

    if (arbitrage_opportunity < 1) {
        printf("Arbitrage opportunity found!\n");
        printf("Arbitrage percentage: %.2f%%\n", (1 - arbitrage_opportunity) * 100);
        double stake1, stake2, total_stake, profit;
        printf("Enter your total stake: ");
        scanf("%lf", &total_stake);
        stake1 = total_stake * (1 / odds1) / arbitrage_opportunity;
        stake2 = total_stake * (1 / odds2) / arbitrage_opportunity;
        profit = total_stake / arbitrage_opportunity - total_stake;
        printf("Bet %.2f on odds %.2f and %.2f on odds %.2f\n", stake1, odds1, stake2, odds2);
        printf("Guaranteed profit: %.2f\n", profit);
    } else {
        printf("No arbitrage opportunity available.\n");
    }
}

// Function to calculate betting metrics
void calculate_betting_metrics(double stake, double odds, double probability) {
    double expected_value = (odds * probability) - (1 - probability);
    double potential_profit = (stake * odds) - stake;
    double break_even_probability = 1 / odds;

    printf("Expected value: %.2f\n", expected_value);
    printf("Potential profit: %.2f\n", potential_profit);
    printf("Break-even probability: %.2f%%\n", break_even_probability * 100);
}

int main() {
    int choice;
    double odds1, odds2, stake, odds, probability;

    printf("Welcome to the Arbitrage and Betting Calculator!\n");
    printf("1. Calculate Arbitrage Opportunity\n");
    printf("2. Calculate Betting Metrics\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the odds of the first outcome: ");
            scanf("%lf", &odds1);
            printf("Enter the odds of the second outcome: ");
            scanf("%lf", &odds2);
            calculate_arbitrage(odds1, odds2);
            break;
        case 2:
            printf("Enter your stake: ");
            scanf("%lf", &stake);
            printf("Enter the odds: ");
            scanf("%lf", &odds);
            printf("Enter the probability of the outcome (as a decimal): ");
            scanf("%lf", &probability);
            calculate_betting_metrics(stake, odds, probability);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

