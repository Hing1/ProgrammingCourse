//
//  Zhangfei.m
//  three-kingdoms
//
//  Created by kian kwok on 2020/10/6.
//

#import "Zhangfei.h"

@implementation Zhangfei
- (instancetype)init {
    self = [super init];
    if (self) {
        _name = @"张飞";
        _country = @"蜀国";
        _blood_value = 6341;
        _energy_value = 100;
        _damage_value = 1510;
        _defense_value = 540;
        _agility_value = 50;
        _isAlive = YES;
    }
    return self;
}
- (NSInteger)skill1 {
    int consume = 10;
    if (_energy_value < consume)
        return -1;
    int hurt = 950;
    NSLog(@"’%@‘使用技能‘画地为牢’输出 %4d 的伤害", _name, hurt);
    _energy_value -= consume;
    if (_agility_value >= 10) {
        _agility_value -= 10;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
- (NSInteger)skill2 {
    int consume = 10;
    if (_energy_value < consume)
        return -1;
    int hurt = 630;
    int cure = 375;
    NSLog(@"‘%@’使用技能‘守护机关’输出 %4d 的伤害", _name, hurt);
    NSLog(@"              ‘%@’ 增加 %4d 的防御", _name, cure);
    _defense_value += cure;
    _energy_value -= consume;
    if (_agility_value >= 10) {
        _agility_value -= 10;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
- (NSInteger)unique_skill {
    int consume = 30;
    if (_energy_value < consume)
        return -1;
    int hurt = 1650;
    NSLog(@"'%@'使用大招'狂兽血性'输出 %4d 的伤害", _name, hurt);
    _energy_value -= consume;
    if (_agility_value >= 30) {
        _agility_value -= 30;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
@end
