/*
Name: KANSIIME MARINA
Registration Number: 25/U/BIO/01378/PD
 */


#include <stdio.h>


// Get grade letter using if...else
char getGrade(int score) {
    if (score >= 80) return 'A';
    else if (score >= 70) return 'B';
    else if (score >= 60) return 'C';
    else if (score >= 50) return 'D';
    else return 'F';
}

// Get grade point using switch
int getGradePoint(char grade) {
    switch (grade) {
        case 'A': return 5;
        case 'B': return 4;
        case 'C': return 3;
        case 'D': return 2;
        case 'F': return 0;
        default: return 0;
    }
}

int main() {

    int scores[16];
    int credits[16] = {
        4,3,3,3,3,3,2,3,
        4,3,3,3,3,3,3,3
    };

    char *courses[16] = {
        "TEMB1101","TEMB1102","TEMB1103","TEMB1104",
        "TEMB1105","TEMB1106","TEMB1107","TEMB1108",
        "TEMB1201","TEMB1202","TEMB1203","TEMB1204",
        "TEMB1205","TEMB1206","TEMB1207","TEMB1208"
    };

    int i;

    // ===== INPUT =====
    for(i = 0; i < 16; i++) {
        // printf("Enter score for %s: ", courses[i]);
        scanf("%d", &scores[i]);

        if(scores[i] < 0 || scores[i] > 100) {
            printf("Invalid score entered\n");
            return 0;
        }
    }

    float sem1_points = 0, sem2_points = 0;
    int sem1_credits = 0, sem2_credits = 0;

    printf("\n=========== ACADEMIC REPORT ===========\n");
    printf("%-10s %-6s %-6s %-6s %-6s %-10s\n",
           "Course","Score","Grade","GP","CU","Weight");

    // ===== PROCESS =====
    for(i = 0; i < 16; i++) {

        char grade = getGrade(scores[i]);        // if...else used
        int gp = getGradePoint(grade);           // switch used
        float weight = gp * credits[i];

        printf("%-10s %-6d %-6c %-6d %-6d %-10.2f\n",
               courses[i], scores[i], grade, gp, credits[i], weight);

        if(i < 8) {
            sem1_points += weight;
            sem1_credits += credits[i];
        } else {
            sem2_points += weight;
            sem2_credits += credits[i];
        }
    }

    // ===== GPA CALCULATIONS =====
    float gpa1 = sem1_points / sem1_credits;
    float gpa2 = sem2_points / sem2_credits;
    float cgpa = (sem1_points + sem2_points) / (sem1_credits + sem2_credits);

    // ===== CLASSIFICATION (if...else) =====
    char *classification;

    if (cgpa >= 4.40)
        classification = "First Class";
    else if (cgpa >= 3.60)
        classification = "Second Class Upper";
    else if (cgpa >= 2.80)
        classification = "Second Class Lower";
    else if (cgpa >= 2.00)
        classification = "Pass";
    else
        classification = "Fail";

    printf("=======================================\n");

    // ===== REQUIRED OUTPUT =====
    printf("Semester I GPA: %.2f\n", gpa1);
    printf("Semester II GPA: %.2f\n", gpa2);
    printf("CGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", classification);

    return 0;
}
