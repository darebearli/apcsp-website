#include <stdio.h>
#include <string.h>

int websiteScore(char* answers[]) {
  const char *booleans[10];
  booleans[0] = "T";
  booleans[1] = "F";
  booleans[2] = "F";
  booleans[3] = "F";
  booleans[4] = "F";
  booleans[5] = "T";
  booleans[6] = "T";
  booleans[7] = "T";
  booleans[8] = "F";
  booleans[9] = "F";

  int i;
  int score;
  for (i=0; i<10;i++) {
    int g = i+1;
    if (strcmp(answers[g], "T") != 0 && strcmp(answers[g], "F") != 0) {
      printf("Q%d: We couldn't read your answer. Please put in T or F only.\n", g);
    }
    else {
      if (strcmp(answers[g],booleans[i]) == 0) {
        printf("Q%d: Nice! You got the correct answer!\n", g);
        score = score + 1;
      }
      else { 
        printf("Q%d: Oops! Not quite.\n", g);
      }
    }
  }
  printf("Your final score was %d! Congratulations!\n", score);
}

int checkScore(char str[20], int i) { 
  const char *booleans[10];
  booleans[0] = "T";
  booleans[1] = "F";
  booleans[2] = "F";
  booleans[3] = "F";
  booleans[4] = "F";
  booleans[5] = "T";
  booleans[6] = "T";
  booleans[7] = "T";
  booleans[8] = "F";
  booleans[9] = "F";

  while (strcmp(str, "T") != 0 && strcmp(str, "F") != 0) {
    printf("Please put in T or F only.\n");
    char again[20];
    scanf("%s", str);
  }
 
  if (strcmp(str, "T") == 0 || strcmp(str, "F") == 0) {
    if (strcmp(str, booleans[i]) == 0) {
      printf("You got it correct\n");
      printf("The answer was %s\n", booleans[i]);
      return 1;
    }
    else {
      printf("Sorry, that's wrong.\n");
      printf("The actual answer was %s\n", booleans[i]);
      return 0;
    }
  }
  return 0;
}

int playquiz(int numberArg, char* answers[]) {
  const char *questions[10];
  questions[0] = "Ray Allen currently holds the record for most 3 pointers made";
  questions[1] = "The Neew England Patriots have won the most NFL championships";
  questions[2] = "Liverpool FC has the most Champions League titles in history";
  questions[3] = "Stephen Curry holds the record for most threes in NBA history";
  questions[4] = "LeBron James has three MVPs";
  questions[5] = "Jayson Tatum is only 20 years old";
  questions[6] = "Russell Westbrook shoots less than 40 percent from the field";
  questions[7] = "Ben Simmons is a two time Rookie of the Year";
  questions[8] = "The Clippers have made it to the Western Conference Finals";
  questions[9] = "Eli Manning is a quarterback in the NFL";

  printf("Hello, and welcome to this sports quiz\n");
  printf("Put in 'T' for True and 'F' for False\n");

  if (numberArg == 0) {
    int i;
    int realScore = 0;
    for (i=0;i<10;i++) {
      char str[10];

      printf("True or False: %s\n", questions[i]);
      scanf("%s", str);
      int score = checkScore(str, i);
      printf("%d\n", score);
      realScore = score + realScore;
      printf("%d\n", realScore);
      if (i == 9) {
        printf("You're Score was %d: Congratulations.\n", realScore);
      } 
    }
  }
  else {
    websiteScore(answers);
  }
  return 0;
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    int place = 0;
    playquiz(place, argv);
  }
  else {
    playquiz(argc, argv);
  }
  return 0;
}
