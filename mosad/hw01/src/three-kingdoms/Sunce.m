//
//  Sunce.m
//  three-kingdoms
//
//  Created by kian kwok on 2020/10/6.
//

#import "Sunce.h"

@implementation Sunce
- (instancetype)init {
    self = [super init];
    if (self) {
        _name = @"孙策";
        _country = @"吴国";
        _blood_value = 5000;
        _energy_value = 1000;
        _damage_value = 1354;
        _defense_value = 390;
        _agility_value = 80;
        _isAlive = YES;
    }
    return self;
}
- (NSInteger)skill1 {
    int consume = 50;
    if (_energy_value < consume)
        return -1;
    int hurt = 1550;
    NSLog(@"’%@‘使用技能‘劈风斩浪’输出 %4d 的伤害", _name, hurt);
    _energy_value -= consume;
    if (_agility_value >= 10) {
        _agility_value -= 10;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
- (NSInteger)skill2 {
    int consume = 70;
    if (_energy_value < consume)
        return -1;
    int hurt = 630;
    int cure = _damage_value * 0.25;
    NSLog(@"’%@‘使用技能‘惊涛骇浪’输出 %4d 的伤害", _name, hurt);
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
- (NSInteger)unique_skill {
    int consume = 100;
    if (_energy_value < consume)
        return -1;
    int hurt = 2650;
    NSLog(@"’%@‘使用技能‘长帆破浪’输出 %4d 的伤害", _name, hurt);
    _energy_value -= consume;
    if (_agility_value >= 30) {
        _agility_value -= 30;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
@end
