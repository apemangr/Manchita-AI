#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TRAIN_COUNT sizeof(train)/sizeof(train[0])

float train[][2] = {
    {0, 0},
    {1, -2},
    {2, -4}, 
    {3, -6},
};

float rand_float(void)
{
    return (float)rand()/(float)RAND_MAX;
}

float cost(float w){
    float result = 0.0f;
    for (size_t i = 0; i < TRAIN_COUNT; i++) {
        float x = train[i][0];
        float y = x * w;
        float d = y - train[i][1];
        result += d*d;
    }
    result /= TRAIN_COUNT;
    return result;
}

int main()
{
    srand(69);
    float w = rand_float()*10.0f;
    float eps = 1e-3;
    float rate = 1e1;
    
    for (int i = 0 ; i < 70; i++) {
        float dcost = (cost(w+eps)-cost(w));
        w -= rate * dcost;
        printf("%f\n", cost(w));
    }
    printf("------------------------------\n");
    printf("%f\n",w);
    return 0;
}

