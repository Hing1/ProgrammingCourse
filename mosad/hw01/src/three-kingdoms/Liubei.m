//
//  Liubei.m
//  three-kingdoms
//
//  Created by kian kwok on 2020/10/6.
//

#import "Liubei.h"

@implementation Liubei
- (instancetype)init {
    self = [super init];
    if (self) {
        _name = @"刘备";
        _country = @"蜀国";
        _blood_value = 4300;
        _energy_value = 750;
        _damage_value = 654;
        _defense_value = 890;
        _agility_value = 70;
        _isAlive = YES;
    }
    return self;
}
- (NSInteger)skill1 {
    int consume = 60;
    if (_energy_value < consume)
        return -1;
    int hurt = 750;
    int cure = _agility_value * 0.3;
    NSLog(@"’%@‘使用技能‘双重射击’输出 %4d 的伤害", _name, hurt);
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
- (NSInteger)skill2 {
    int consume = 80;
    if (_energy_value < consume)
        return -1;
    int hurt = 1000;
    NSLog(@"’%@‘使用技能‘身先士卒’输出 %4d 的伤害", _name, hurt);
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
    int hurt = 200;
    int cure = _defense_value * 0.4;
    NSLog(@"’%@‘使用技能‘以德服人’输出 %4d 的伤害", _name, hurt);
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
