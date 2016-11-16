// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from field.djinni

#import "SDField.h"


@implementation SDField

- (nonnull instancetype)initWithWalls:(nonnull SDWalls *)walls
                               snakes:(nonnull NSArray<SDSnakeModel *> *)snakes
                              mySnake:(nullable SDSnakeModel *)mySnake
                              bonuses:(nonnull NSArray<SDVectorModel *> *)bonuses
{
    if (self = [super init]) {
        _walls = walls;
        _snakes = [snakes copy];
        _mySnake = mySnake;
        _bonuses = [bonuses copy];
    }
    return self;
}

+ (nonnull instancetype)fieldWithWalls:(nonnull SDWalls *)walls
                                snakes:(nonnull NSArray<SDSnakeModel *> *)snakes
                               mySnake:(nullable SDSnakeModel *)mySnake
                               bonuses:(nonnull NSArray<SDVectorModel *> *)bonuses
{
    return [[self alloc] initWithWalls:walls
                                snakes:snakes
                               mySnake:mySnake
                               bonuses:bonuses];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p walls:%@ snakes:%@ mySnake:%@ bonuses:%@>", self.class, (void *)self, self.walls, self.snakes, self.mySnake, self.bonuses];
}

@end
