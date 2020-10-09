//
//  Guanyu.m
//  three-kingdoms
//
//  Created by kian kwok on 2020/10/6.
//

#import "Guanyu.h"

@implementation Guanyu
- (instancetype)init {
    self = [super init];
    if (self) {
        _name = @"关羽";
        _country = @"蜀国";
        _blood_value = 4383;
        _energy_value = 0;
        _damage_value = 3000;
        _defense_value = 400;
        _agility_value = 60;
        _isAlive = YES;
    }
    return self;
}
- (NSInteger)skill1 {
    int hurt = 1290;
    NSLog(@"’%@‘使用技能‘单刀赴会’输出 %4d 的伤害", _name, hurt);
    if (_agility_value >= 10) {
        _agility_value -= 10;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
- (NSInteger)skill2 {
    int hurt = 1010;
    int cure = 0.04 * _agility_value;
    NSLog(@"’%@‘使用技能‘青龙偃月’输出 %4d 的伤害", _name, hurt);
    NSLog(@"              ‘%@’ 增加 %4d 的灵敏", _name, cure);
    _agility_value += cure;
    if (_agility_value >= 10) {
        _agility_value -= 10;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
- (NSInteger)unique_skill {
    int hurt = 1750 + 0.3 * _damage_value;
    NSLog(@"’%@‘使用技能‘刀锋铁骑’输出 %4d 的伤害", _name, hurt);
    if (_agility_value >= 30) {
        _agility_value -= 30;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
@end
