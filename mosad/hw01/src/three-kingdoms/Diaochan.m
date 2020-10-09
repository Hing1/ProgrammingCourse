//
//  Diaochan.m
//  three-kingdoms
//
//  Created by kian kwok on 2020/10/6.
//

#import "Diaochan.h"

@implementation Diaochan
- (instancetype)init {
    self = [super init];
    if (self) {
        _name = @"貂蝉";
        _country = @"中立";
        _blood_value = 6560;
        _energy_value = 1000;
        _damage_value = 530;
        _defense_value = 660;
        _agility_value = 75;
        _isAlive = YES;
    }
    return self;
}
- (NSInteger)skill1 {
    int consume = 40;
    if (_energy_value < consume)
        return -1;
    int hurt = 100 + _damage_value * 0.5;
    NSLog(@"’%@‘使用技能‘语落红雨’输出 %4d 的伤害", _name, hurt);
    _energy_value -= consume;
    if (_agility_value >= 10) {
        _agility_value -= 10;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
- (NSInteger)skill2 {
    int consume = 50;
    if (_energy_value < consume)
        return -1;
    int hurt = 600 + _damage_value * 0.36;
    NSLog(@"’%@‘使用技能‘语缘心结’输出 %4d 的伤害", _name, hurt);
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
    int hurt = 560 + _damage_value * 0.5;
    int cure = _energy_value * 0.04;
    NSLog(@"’%@‘使用技能‘语绽风华’输出 %4d 的伤害", _name, hurt);
    NSLog(@"              ‘%@’ 增加 %4d 的能量", _name, cure);
    _energy_value += cure;
    _energy_value -= consume;
    if (_agility_value >= 30) {
        _agility_value -= 30;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
@end
