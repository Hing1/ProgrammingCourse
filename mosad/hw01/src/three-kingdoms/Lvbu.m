//
//  Lvbu.m
//  three-kingdoms
//
//  Created by kian kwok on 2020/10/6.
//

#import "Lvbu.h"

@implementation Lvbu
- (instancetype)init {
    self = [super init];
    if (self) {
        _name = @"吕布";
        _country = @"中立";
        _blood_value = 3344;
        _energy_value = 50;
        _damage_value = 2354;
        _defense_value = 390;
        _agility_value = 75;
        _isAlive = YES;
    }
    return self;
}
- (NSInteger)skill1 {
    int consume = 10;
    if (_energy_value < consume)
        return -1;
    int hurt = 1300;
    int cure = _blood_value * 0.04;
    NSLog(@"’%@‘使用技能‘方天画斩’输出 %4d 的伤害", _name, hurt);
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
- (NSInteger)skill2 {
    int consume = 10;
    if (_energy_value < consume)
        return -1;
    int hurt = 630;
    int cure = _defense_value * 0.5;
    NSLog(@"’%@‘使用技能‘贪狼之握’输出 %4d 的伤害", _name, hurt);
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
    int hurt = 1650 + 0.5 * _damage_value;
    int cure = _blood_value * 0.04;
    NSLog(@"’%@‘使用技能‘魔神降世’输出 %4d 的伤害", _name, hurt);
    NSLog(@"              ‘%@’ 增加 %4d 的生命", _name, cure);
    _energy_value -= consume;
    _blood_value += cure;
    if (_agility_value >= 30) {
        _agility_value -= 30;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
@end
