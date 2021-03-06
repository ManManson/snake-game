// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from point.djinni

#import "SDPoint.h"


@implementation SDPoint

- (nonnull instancetype)initWithX:(int32_t)x
                                y:(int32_t)y
{
    if (self = [super init]) {
        _x = x;
        _y = y;
    }
    return self;
}

+ (nonnull instancetype)pointWithX:(int32_t)x
                                 y:(int32_t)y
{
    return [[self alloc] initWithX:x
                                 y:y];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p x:%@ y:%@>", self.class, (void *)self, @(self.x), @(self.y)];
}

@end
