//
//  main.cpp
//  TestPoint
//
//  Created by 何欢 on 2018/11/4.
//  Copyright © 2018年 何欢. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int a[5] = {1, 2, 3, 4, 5};
    int *p = (int *)(&a + 1);
    printf("0x%08X, 0x%08X\n", a, &a);
    printf("%d, %d \n", *(a + 1), *(p - 1));
    return 0;
}
