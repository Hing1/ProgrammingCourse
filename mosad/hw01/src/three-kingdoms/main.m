//
//  main.m
//  three-kingdoms
//
//  Created by kian kwok on 2020/10/6.
//

#import <Foundation/Foundation.h>
#import "Guanyu.h"
#import "Liubei.h"
#import "Zhangfei.h"
#import "Lvbu.h"
#import "Sunce.h"
#import "Diaochan.h"
#import "Zhaoyun.h"
#import "Dianwei.h"
#import "Huangzhong.h"
#import "Zhouyu.h"
#import "Machao.h"

int NUM_HEROS = 11;

NSInteger attack_by(Hero *h);
void pkround(Hero *h1, Hero *h2);
void PK(Hero *h1, Hero *h2);
Hero *selectHero(int n);
void randomSelect(void);
void inputSelect(void);

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSLog(@"Choose heroes randomly or manually?");
        NSLog(@"    1. Random select");
        NSLog(@"    2. Input  select");
        int n = 0;
        scanf("%d", &n);
        n = n % 2;
        if (n == 1) {
            randomSelect();
        } else {
            inputSelect();
        }
        NSLog(@"Hello world is the best end!");
    }
    return 0;
}

NSInteger attack_by(Hero *h) {
    int x = 0;
    NSInteger hurt = 0;
    do {
        x = arc4random() % 4;
        switch (x) {
            case 1:
                hurt = [h skill1];
                break;
            case 2:
                hurt = [h skill2];
                break;
            case 3:
                hurt = [h unique_skill];
                break;
            default:
                hurt = [h common_attack];
                break;
        }
    } while (hurt == -1);
    return hurt;
}
void pkround(Hero *h1, Hero *h2) {
    NSInteger hurt1 = 0;
    NSInteger hurt2 = 0;
    if ([h1 getAgility_value] > [h2 getAgility_value]) {
        hurt1 = [h2 be_injured:attack_by(h1)];
        if ([h2 Alive]) {
            hurt2 = [h1 be_injured:attack_by(h2)];
            if (hurt1 >= hurt2)
                NSLog(@"In this round, %@ has the advantage.", [h1 getName]);
            else
                NSLog(@"In this round, %@ has the advantage.", [h2 getName]);
        } else {
            NSLog(@"In this round, %@ has the advantage.", [h1 getName]);
        }
    } else {
        hurt2 = [h1 be_injured:attack_by(h2)];
        if ([h1 Alive]) {
            hurt1 = [h2 be_injured:attack_by(h1)];
            if (hurt2 >= hurt1)
                NSLog(@"In this round, %@ has the advantage.", [h2 getName]);
            else
                NSLog(@"In this round, %@ has the advantage.", [h1 getName]);
        } else {
            NSLog(@"In this round, %@ has the advantage.", [h2 getName]);
        }
    }
}
void PK(Hero *h1, Hero *h2) {
    NSLog(@"Hero 1");
    [h1 print_status];
    NSLog(@"Hero 2");
    [h2 print_status];
    for (int i = 0; i < 10; ++i) {
        putchar(10);
        NSLog(@"***************************************");
        NSLog(@"Round No.%d:", i + 1);
        pkround(h1, h2);
        [h1 print_status];
        [h2 print_status];
        NSLog(@"***************************************");
        if (!([h1 Alive] && [h2 Alive]))
            break;
    }
    putchar(10);
    if ([h1 getBlood_value] > [h2 getBlood_value]) {
        NSLog(@"Game result: %@ win!", [h1 getName]);
    } else if ([h1 getBlood_value] < [h2 getBlood_value]) {
        NSLog(@"Game result: %@ win!", [h2 getName]);
    } else {
        NSLog(@"The game has drawn.!");
    }
}
Hero *selectHero(int n) {
    Hero *h;
    switch (n) {
        case 1:
            h = [Guanyu new];
            break;
        case 2:
            h = [Liubei new];
            break;
        case 3:
            h = [Zhangfei new];
            break;
        case 4:
            h = [Lvbu new];
            break;
        case 5:
            h = [Sunce new];
            break;
        case 6:
            h = [Diaochan new];
            break;
        case 7:
            h = [Zhaoyun new];
            break;
        case 8:
            h = [Dianwei new];
            break;
        case 9:
            h = [Huangzhong new];
            break;
        case 10:
            h = [Zhouyu new];
            break;
        default:
            h = [Machao new];
            break;
    }
    return h;
}
void randomSelect(void) {
    int n1 = arc4random() % NUM_HEROS;
    int n2 = arc4random() % NUM_HEROS;
    while (n2 == n1) {
        n2 = arc4random() % NUM_HEROS;
    }
    Hero *h1 = selectHero(n1);
    Hero *h2 = selectHero(n2);
    PK(h1, h2);
}
void inputSelect(void) {
    int n1 = 0, n2 = 0;
    NSLog(@"Here is the table of heros.");
    NSLog(@"    1.关羽    2.刘备");
    NSLog(@"    3.张飞    4.吕布");
    NSLog(@"    5.孙策    6.貂蝉");
    NSLog(@"    7.赵云    8.典韦");
    NSLog(@"    9.黄忠   10.周瑜");
    NSLog(@"   11.马超");
    NSLog(@"Please selece hero 1:");
    scanf("%d", &n1);
    NSLog(@"Please selece hero 2:");
    scanf("%d", &n2);
    while (n1 == n2) {
        NSLog(@"Please re selece another hero:");
        scanf("%d", &n2);
    }
    Hero *h1 = selectHero(n1 % NUM_HEROS);
    Hero *h2 = selectHero(n2 % NUM_HEROS);
    PK(h1, h2);
}
