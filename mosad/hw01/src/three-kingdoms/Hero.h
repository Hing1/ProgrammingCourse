//
//  Hero.h
//  three-kingdoms
//
//  Created by kian kwok on 2020/10/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Hero : NSObject {
    NSString *_name;
    NSString *_country;
    NSInteger _blood_value;
    NSInteger _energy_value;
    NSInteger _damage_value;
    NSInteger _defense_value;
    NSInteger _agility_value;
    BOOL _isAlive;
}

- (void)print_status;
- (void)PKOneUnit;
- (NSString *)getName;
- (NSString *)getCountry;
- (NSInteger)getBlood_value;
- (NSInteger)getEnergy_value;
- (NSInteger)getAgility_value;
- (NSInteger)common_attack;
- (NSInteger)skill1;
- (NSInteger)skill2;
- (NSInteger)unique_skill;
- (NSInteger)be_injured:(NSInteger)damage;
- (BOOL)Alive;

@end

NS_ASSUME_NONNULL_END
