//
//  Hero.m
//  three-kingdoms
//
//  Created by kian kwok on 2020/10/6.
//

#import "Hero.h"

@implementation Hero

- (void)PKOneUnit {

}
- (NSString *)getName {
    return _name;
}
- (NSString *)getCountry {
    return _country;
}
- (NSInteger)getBlood_value {
    return _blood_value;
}
- (NSInteger)getEnergy_value {
    return _energy_value;
}

- (NSInteger)getAgility_value {
    return _agility_value;
}
- (NSInteger)common_attack {
    NSLog(@"’%@‘使用技能‘普通攻击’输出 %4ld 的伤害", _name, _damage_value);
    return _damage_value;
}
- (NSInteger)skill1 {
    NSLog(@"’%@‘使用技能‘第一技能’输出 %4ld 的伤害", _name, _damage_value);
    return _damage_value;
}
- (NSInteger)skill2 {
    NSLog(@"’%@‘使用技能‘第二技能’输出 %4ld 的伤害", _name, _damage_value);
    return _damage_value;
}
- (NSInteger)unique_skill {
    NSLog(@"’%@‘使用大招‘终极必杀’输出 %4ld 的伤害", _name, _damage_value);
    return _damage_value;
}
- (NSInteger)be_injured:(NSInteger)damage {
    NSInteger hurt = 0;
    if (damage > _defense_value) {
        hurt = damage - _defense_value;
    }
    NSLog(@"              ‘%@’ 受到 %4ld 的伤害", _name, hurt);
    if (hurt >= _blood_value) {
        _blood_value = 0;
        _isAlive = NO;
    } else {
        _blood_value -= hurt;
    }
    return hurt;
}
- (BOOL)Alive {
    return _isAlive;
}
- (void)print_status {
    NSLog(@"%@'s status:", _name);
    NSLog(@"    Blood  : %ld", _blood_value);
    NSLog(@"    Energy : %ld", _energy_value);
    NSLog(@"    Damage : %ld", _damage_value);
    NSLog(@"    Defense: %ld", _defense_value);
    NSLog(@"    Agility: %ld", _agility_value);
}

@end
