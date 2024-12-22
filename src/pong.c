#include <math.h>
#include <stdio.h>

int place(int ball_x, int ball_y, int leftp, int rightp, int leftscore, int rightscore) {
    printf("%d СЧЕТ %d\n", leftscore, rightscore);
    for (int y = 0; y < 26; y++) {
        for (int x = 0; x < 81; x++) {
            if (y == 0 || y == 25) {
                (x != 80) ? printf("-") : printf("-\n");
            } else if (x == 0 || x == 80) {
                (x != 80) ? printf("|") : printf("|\n");
            } else if (ball_x == x && ball_y == y) {
                printf("*");
            } else if ((x == 1 && y == leftp) || (x == 1 && y == leftp + 1) || (x == 1 && y == leftp + 2)) {
                printf("#");
            } else if ((x == 79 && y == rightp) || (x == 79 && y == rightp + 1) ||
                       (x == 79 && y == rightp + 2)) {
                printf("#");
            } else {
                printf(" ");
            }
        }
    }
    return 1;
}

int main() {
    int ball_x = 40, ball_y = 12;
    int leftp = 11, rightp = 11;
    int dx = 1, dy = 1;
    int rightscore = 0, leftscore = 0;
    while (rightscore != 21 && leftscore != 21) {
        place(ball_x, ball_y, leftp, rightp, leftscore, rightscore);
        char move = getchar();
        if (move == 'a' || move == 'z' || move == 'k' || move == 'm' || move == ' ') {
            ball_x += dx;
            ball_y += dy;
        } else
            printf("Введите корректный символ\n");
        if (ball_y == 1 || ball_y == 24) dy = -dy;
        if (ball_x == 2 && (ball_y == leftp || ball_y == leftp + 1 || ball_y == leftp + 2)) dx = -dx;
        if (ball_x == 78 && (ball_y == rightp || ball_y == rightp + 1 || ball_y == rightp + 2)) dx = -dx;
        if (ball_x == 1) {
            rightscore++;
            ball_x = 40;
            ball_y = 12;
            leftp = 11;
            rightp = 11;
            dx = 1;
            dy = 1;
        }
        if (ball_x == 79) {
            leftscore++;
            ball_x = 40;
            ball_y = 12;
            leftp = 11;
            rightp = 11;
            dx = -1;
            dy = -1;
        }
        if ((move == 'a') && leftp > 1)
            leftp--;
        else if ((move == 'z') && leftp < 22)
            leftp++;
        if ((move == 'k') && rightp > 1)
            rightp--;
        else if ((move == 'm') && rightp < 22)
            rightp++;
        while (getchar() != '\n')
            ;
        if (leftscore == 21)
            printf("Игрок слева победил!!! Поздравляем\n");
        else if (rightscore == 21)
            printf("Игрок справа победил!!! Поздравляем\n");
    }
    return 0;
}
