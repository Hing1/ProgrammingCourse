//
//  Zhaoyun.m
//  three-kingdoms
//
//  Created by kian kwok on 2020/10/6.
//

#import "Zhaoyun.h"

@implementation Zhaoyun
- (instancetype)init {
    self = [super init];
    if (self) {
        _name = @"赵云";
        _country = @"蜀国";
        _blood_value = 4300;
        _energy_value = 500;
        _damage_value = 1154;
        _defense_value = 890;
        _agility_value = 70;
        _isAlive = YES;
    }
    return self;
}
- (NSInteger)skill1 {
    int consume = 30;
    if (_energy_value < consume)
        return -1;
    NSInteger hurt = 300 + _damage_value * 0.6;
    NSLog(@"’%@‘使用技能‘惊雷之龙’输出 %4ld 的伤害", _name, hurt);
    _energy_value -= consume;
    if (_agility_value >= 10) {
        _agility_value -= 10;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
- (NSInteger)skill2 {
    int consume = 80;
    if (_energy_value < consume)
        return -1;
    NSInteger hurt = 175 + _damage_value * 0.4;
    int cure = hurt * 0.2;
    NSLog(@"’%@‘使用技能‘破云之龙’输出 %4ld 的伤害", _name, hurt);
    NSLog(@"              ‘%@’ 增加 %4d 的生命", _name, cure);
    _blood_value += cure;
    _energy_value -= consume;
    if (_agility_value >= 10) {
        _agility_value -= 10;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
- (NSInteger)unique_skill {
    int consume = 130;
    if (_energy_value < consume)
        return -1;
    NSInteger hurt = 500 + _damage_value;
    NSLog(@"’%@‘使用技能‘天翔之龙’输出 %4ld 的伤害", _name, hurt);
    _energy_value -= consume;
    if (_agility_value >= 30) {
        _agility_value -= 30;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
@end
