//
//  Zhouyu.m
//  three-kingdoms
//
//  Created by kian kwok on 2020/10/6.
//

#import "Zhouyu.h"

@implementation Zhouyu
- (instancetype)init {
    self = [super init];
    if (self) {
        _name = @"周瑜";
        _country = @"吴国";
        _blood_value = 5513;
        _energy_value = 1970;
        _damage_value = 900;
        _defense_value = 500;
        _agility_value = 75;
        _isAlive = YES;
    }
    return self;
}
- (NSInteger)skill1 {
    int consume = 60;
    if (_energy_value < consume)
        return -1;
    int hurt = 400 + 0.2 * _damage_value;
    int cure = _agility_value * 0.1;
    NSLog(@"’%@‘使用技能‘东风浩荡’输出 %4d 的伤害", _name, hurt);
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
    int consume = 50;
    if (_energy_value < consume)
        return -1;
    int hurt = 500 + 0.3 * _damage_value;
    NSLog(@"’%@‘使用技能‘流火之矢’输出 %4d 的伤害", _name, hurt);
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
    int hurt = 800 + 0.4 * _damage_value;
    NSLog(@"’%@‘使用技能‘烽火赤壁’输出 %4d 的伤害", _name, hurt);
    _energy_value -= consume;
    if (_agility_value >= 30) {
        _agility_value -= 30;
    } else {
        _agility_value = 0;
    }
    return hurt;
}
@end
