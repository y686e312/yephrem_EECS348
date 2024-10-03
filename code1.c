//function for the score combinations
void Scorigami(int score) 
{
    //defining variables 
    int score;
    int TD; 
    int FG; 
    int S;
    int TD_2PT; 
    int TD_FG;

    printf("Enter the score: "); //asking user for a score
    scanf("%d", &score); //saving that score to in a variable to be run as the parameter in the function

    printf("Possible combinations of scoring plays if a teams score is %d\n", score);
    
    //loops through every possible scoring method in football
    for (TD_FG = 0; TD_FG * 7 <= score; TD_FG++) 
    { 
        for (FG = 0; FG * 3 <= score; FG++) 
        { 
            for (TD = 0; TD * 6 <= score; TD++) 
            { 
                for (TD_2PT = 0; TD_2PT * 8 <= score; TD_2PT++) 
                { 
                    for (S = 0; S * 2 <= score; S++) 
                    { 
                        int total = TD * 6 + FG * 3 + S * 2 + TD_2PT * 8 + TD_FG * 7;
                        //stops the loop when the total is equal to the entered score and prints how it got to that score
                        if (total == score) 
                        {
                            printf("%d TD + 2PT, %d TD + FG, %d TD, %d FG, %d Safety\n", 
                                   TD_2PT, TD_FG, TD, FG, S);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    Scorigami();
    return 0;
}
