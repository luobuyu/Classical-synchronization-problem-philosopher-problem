#ifndef CONST_H
#define CONST_H


const int MAXN = 5;
const int REST = 0;
const int THINK = 1;
const int EAT = 2;
const int LEFT = 3;
const int RIGHT = 4;
const int FULL = 5;
const int INIT = 0;
const int CIRCLE_X = 295;
const int CIRCLE_Y = 320;
const int MIN_RADIUS = 210;
const int MAX_RADIUS = 280;
const char STATUS_NAME[6][10] = {"休息", "思考", "吃饭", "左筷", "右筷", "双筷"};
const int INIT_POS[5][3] = {
    {390, 170, 36},
    {460, 370, 108},
    {295, 500, 180},
    {140, 365, 252},
    {190, 190, 324},
};

const int SET_POS[2][5][3] = {
    {
        {325, 130, 0},
        {490, 290, 72},
        {375, 490, 144},
        {160, 450, 216},
        {125, 230, 288},
    },
    {
        {255, 130, 0},
        {450, 210, 72},
        {440, 435, 144},
        {220, 490, 216},
        {100, 295, 288}
    }
};

const int SIZE = 1;
#endif // CONST_H
