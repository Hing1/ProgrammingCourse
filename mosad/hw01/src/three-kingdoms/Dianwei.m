//
//  Dianwei.m
//  three-kingdoms
//
//  Created by kian kwok on 2020/10/6.
//

#import "Dianwei.h"

@implementation Dianwei
- (instancetype)init {
    self = [super init];
    if (self) {
        _name = @"典韦";
        _country = @"魏国";
        _blood_value = 5500;
        _energy_value = 1600;
        _damage_value = 2200;
        _defense_value = 125;
        _agility_value = 60;
        _isAlive = YES;
    }
    return self;
}
- (NSInteger)skill1 {
    int consume = 55;
    if (_energy_value < consume)
        return -1;
    NSInteger hurt = 400 + _damage_value;
    NSLog(@"’%@‘使用技能‘激怒红眼’输出 %4ld 的伤害", _name, hurt);
    _energy_value -= consume;
    if (_agility_value >= 10) {
        _agility_value -= 10;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
- (NSInteger)skill2 {
    int consume = 65;
    if (_energy_value < consume)
        return -1;
    NSInteger hurt = 400 + _damage_value;
    int cure =  hurt * 0.01;
    NSLog(@"’%@‘使用技能‘激怒狂暴’输出 %4ld 的伤害", _name, hurt);
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
    int hurt = 450 + 1.2 * _damage_value;
    int cure =  hurt * 0.03;
    NSLog(@"’%@‘使用技能‘激怒嗜血’输出 %4d 的伤害", _name, hurt);
    NSLog(@"              ‘%@’ 增加 %4d 的生命", _name, cure);
    _blood_value += cure;
    _energy_value -= consume;
    if (_agility_value >= 30) {
        _agility_value -= 30;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
@end
