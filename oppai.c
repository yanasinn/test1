#include<stdio.h>
#include<math.h>
#define NUM 3
#define sqr(n) ((n) * (n))

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point p[3];
} Triangle;

double cal_area(Triangle tri){          //面積計算
    double area;
    area = fabs((tri.p[0].x - tri.p[2].x)*(tri.p[1].y - tri.p[2].y) - (tri.p[1].x - tri.p[2].x)*(tri.p[0].y - tri.p[2].y)) / 2;
    return area;
}

void sort(double dist[]){       //昇順ソート関数
    int i, j, tmp;
    for(i = 0; i < NUM; i++){
        for(j = i + 1; j < NUM; j++){
            if(dist[i] > dist[j]){
                tmp = dist[i];
                dist[i] = dist[j];
                dist[j] = tmp;
            }
        }
    }
}

int comp(Triangle a, Triangle b){        //comparison Triangle A with Triangle B
    int i, j = 0;
    double dis_a[3], dis_b[3], err[3], esp = 1.0e-6;
    for(i = 0; i < NUM; i++){
        if(i > 1){
            j = -3;
        }           //各辺の長さを計算
        dis_a[i] = sqrt(sqr(a.p[i].x - a.p[i+1+j].x) + sqr(a.p[i].y - a.p[i+1+j].y));
        dis_b[i] = sqrt(sqr(b.p[i].x - b.p[i+1+j].x) + sqr(b.p[i].y - b.p[i+1+j].y));
	 err[i] = fabs(dis_a[i] - dis_b[i]);
    }
    sort(dis_a);        //辺の長い順に並べ替える
    sort(dis_b);
    
    if(err[0] < esp && err[1] < esp && err[2] < esp){
        return 1;
    } else {
        return 0;
    }
}

Triangle cal_AT(Triangle T, double A[][NUM-1]){          //線形変換
    int i;
    Triangle Milano_Collection_AT;
    for(i = 0; i < NUM; i++){
        Milano_Collection_AT.p[i].x = T.p[i].x * A[0][0] + T.p[i].y * A[0][1];
        Milano_Collection_AT.p[i].y = T.p[i].x * A[1][0] + T.p[i].y * A[1][1];
    }
    return Milano_Collection_AT;
}

int main(void){             //main関数
    int i, j, key;
    double matrix_A[NUM-1][NUM-1];
    Triangle tri[2];
    for(j = 0; j < NUM - 1; j++){
        for(i = 0; i < NUM; i++){
            scanf("%lf", &tri[j].p[i].x);
            scanf("%lf", &tri[j].p[i].y);
        }
    }
    for(j = 0; j < NUM - 1; j++){
        for(i = 0; i < NUM - 1; i++){
            scanf("%lf", &matrix_A[j][i]);
        }
    }
    
    for(j = 0; j < NUM - 1; j++){
        printf("T%d:", j + 1);
        for(i = 0; i < NUM; i++){
            printf("(%.2f, %.2f)", tri[j].p[i].x, tri[j].p[i].y);
        }
        printf("\n");
        double area = cal_area(tri[j]);
        printf("The area of a triangle T%d: %f\n", j + 1, area);
    }
    printf("\n");
    
    key = comp(tri[0], tri[1]);     //合同かどうか調べる
    if(key == 1){
        printf("Congruence.\n");
    } else {
        printf("Not congruence.\n");
    }
    printf("\n");
    
    printf("Matrix A:\n");
    for(j = 0; j < NUM - 1; j++){
        for(i = 0; i < NUM - 1; i++){
            printf("%f ", matrix_A[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    
    for(j = 0; j < NUM - 1; j++){
        printf("AT%d:", j + 1);
        tri[j] = cal_AT(tri[j], matrix_A);
        for(i = 0; i < NUM; i++){
            printf("(%.2f, %.2f)", tri[j].p[i].x, tri[j].p[i].y);
        }
        printf("\n");
        double area = cal_area(tri[j]);
        printf("The area of a triangle AT%d: %f\n", j + 1, area);
    }
    return 0;
}
