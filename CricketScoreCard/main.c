#include <stdio.h>

struct Team {
    char name[30];
    int played, won, lost, draw;
    int points;
};

int main() {
    int n, i;

    printf("Enter number of teams: ");
    scanf("%d", &n);

    int maxMatches;
    printf("Enter maximum matches allowed for each team: ");
    scanf("%d", &maxMatches);

    if (maxMatches <= 0) {
        printf("Error: Maximum matches must be greater than 0.\n");
        return 1;
    }

    struct Team team[n];

    // Input Team Details
    for (i = 0; i < n; i++) {
        printf("\nEnter Team %d Name: ", i + 1);
        scanf("%s", team[i].name);

        printf("Matches Played: ");
        scanf("%d", &team[i].played);

        printf("Matches Won: ");
        scanf("%d", &team[i].won);

        printf("Matches Lost: ");
        scanf("%d", &team[i].lost);

        printf("Matches Draw: ");
        scanf("%d", &team[i].draw);

        // Validation for negative values
        if (team[i].played < 0 || team[i].won < 0 ||
            team[i].lost < 0 || team[i].draw < 0) {
            printf("\nError: Negative values are not allowed!\n");
            return 1;
        }

        // Validation for maximum matches
        if (team[i].played > maxMatches) {
            printf("\nError: %s has played more than the allowed %d matches.\n",
                   team[i].name, maxMatches);
            return 1;
        }

        // Validation for match count
        if (team[i].won + team[i].lost + team[i].draw != team[i].played) {
            printf("\nError: Invalid match data for %s.\n", team[i].name);
            printf("Won + Lost + Draw must be equal to Matches Played.\n");
            return 1;
        }

        // Calculate Points
        team[i].points = (team[i].won * 2) + team[i].draw;
    }

    // Sort by Points (Highest First)
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (team[j].points > team[i].points) {
                struct Team temp = team[i];
                team[i] = team[j];
                team[j] = temp;
            }
        }
    }

    // ✅ Fix: moved printf inside main() — was outside closing brace before
    printf("\n====== CRICKET TOURNAMENT POINTS TABLE ======\n");
    printf("%-15s %-8s %-6s %-6s %-6s %-7s\n",
           "Team", "Played", "Won", "Lost", "Draw", "Points");

    for (i = 0; i < n; i++) {
        printf("%-15s %-8d %-6d %-6d %-6d %-7d\n",
               team[i].name,
               team[i].played,
               team[i].won,
               team[i].lost,
               team[i].draw,
               team[i].points);
    }

    printf("\nTournament completed successfully!\n");
    return 0;
}