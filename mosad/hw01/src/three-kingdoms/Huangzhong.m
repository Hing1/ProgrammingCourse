//
//  Huangzhong.m
//  three-kingdoms
//
//  Created by kian kwok on 2020/10/6.
//

#import "Huangzhong.h"

@implementation Huangzhong
- (instancetype)init {
    self = [super init];
    if (self) {
        _name = @"黄忠";
        _country = @"蜀国";
        _blood_value = 6030;
        _energy_value = 1784;
        _damage_value = 1300;
        _defense_value = 560;
        _agility_value = 40;
        _isAlive = YES;
    }
    return self;
}
- (NSInteger)skill1 {
    int consume = 50;
    if (_energy_value < consume)
        return -1;
    int hurt = 100;
    int cure = 90;
    NSLog(@"’%@‘使用技能‘追击潜能’输出 %4d 的伤害", _name, hurt);
    NSLog(@"              ‘%@’ 增加 %4d 的攻击", _name, cure);
    _damage_value += cure;
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
    int hurt = 800 + 0.6 * _damage_value;
    NSLog(@"’%@‘使用技能‘警戒地雷’输出 %4d 的伤害", _name, hurt);
    _energy_value -= consume;
    if (_agility_value >= 10) {
        _agility_value -= 10;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
- (NSInteger)unique_skill {
    int consume = 80;
    if (_energy_value < consume)
        return -1;
    NSInteger hurt = 700 + _damage_value;
    int cure = _defense_value * 0.04;
    NSLog(@"’%@‘使用技能‘重装炮台’输出 %4ld 的伤害", _name, hurt);
    NSLog(@"              ‘%@’ 增加 %4d 的防御", _name, cure);
    _defense_value += cure;
    _energy_value -= consume;
    if (_agility_value >= 30) {
        _agility_value -= 30;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
@end
