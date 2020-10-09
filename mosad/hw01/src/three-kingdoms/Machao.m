//
//  Machao.m
//  three-kingdoms
//
//  Created by kian kwok on 2020/10/7.
//

#import "Machao.h"

@implementation Machao
- (instancetype)init {
    self = [super init];
    if (self) {
        _name = @"马超";
        _country = @"蜀国";
        _blood_value = 6610;
        _energy_value = 650;
        _damage_value = 2000;
        _defense_value = 200;
        _agility_value = 55;
        _isAlive = YES;
    }
    return self;
}
- (NSInteger)skill1 {
    int consume = 30;
    if (_energy_value < consume)
        return -1;
    int hurt = 400 + 0.6 * _damage_value;
    NSLog(@"’%@‘使用技能‘萧索之刃’输出 %4d 的伤害", _name, hurt);
    _energy_value -= consume;
    if (_agility_value >= 10) {
        _agility_value -= 10;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
- (NSInteger)skill2 {
    int consume = 40;
    if (_energy_value < consume)
        return -1;
    int hurt = 300 + 0.5 * _damage_value;
    int cure = 10;
    NSLog(@"’%@‘使用技能‘日落孤枪’输出 %4d 的伤害", _name, hurt);
    NSLog(@"              ‘%@’ 增加 %4d 的灵敏", _name, cure);
    _agility_value += cure;
    _energy_value -= consume;
    if (_agility_value >= 10) {
        _agility_value -= 10;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
- (NSInteger)unique_skill {
    int consume = 50;
    if (_energy_value < consume)
        return -1;
    int hurt = 800 + 0.7 * _damage_value;
    NSLog(@"’%@‘使用技能‘万刃归鞘’输出 %4d 的伤害", _name, hurt);
    _energy_value -= consume;
    if (_agility_value >= 30) {
        _agility_value -= 30;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
@end
