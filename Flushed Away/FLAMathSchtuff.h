#import <SpriteKit/SpriteKit.h>

#define PolarAdjust(x) x + (M_PI * 0.5f)
static inline CGFloat Deg2Rad(CGFloat deg) { return deg * M_PI/180; }
static inline CGFloat Rad2Deg(CGFloat rad) { return rad * 180/M_PI; }

static inline CGFloat DistanceBetweenPoints(CGPoint p1, CGPoint p2) {
    CGFloat dx = p1.x - p2.x;
    CGFloat dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

static inline CGFloat GravityForceFromPointToPointWithMass(CGPoint p1, CGPoint p2, CGFloat mass) {
    CGFloat distance = DistanceBetweenPoints(p1, p2);
    return 15 * mass / distance;
}

static inline CGVector GravityVectorFromPointToPointWithForce(CGPoint p1, CGPoint p2, CGFloat force) {
    CGFloat dx = p2.x - p1.x;
    CGFloat dy = p2.y - p1.y;
    CGFloat theta = atan2(dy, dx);
    CGFloat fx = cos(theta) * force;
    CGFloat fy = sin(theta) * force;
    return CGVectorMake(fx, fy);
}

static inline CGVector GravityVectorFromPointToPointWithMass(CGPoint p1, CGPoint p2, CGFloat mass) {
    CGFloat F = GravityForceFromPointToPointWithMass(p1, p2, mass);
    return GravityVectorFromPointToPointWithForce(p1, p2, F);
}

static inline CGVector VectorFromSpeedAndAngle(CGFloat speed, CGFloat angle) {
    CGFloat opposite = speed * sin(angle);
    CGFloat adjacent = speed * cos(angle);
    return CGVectorMake(opposite, adjacent);
}

static inline CGFloat AngleBetweenPoints(CGPoint first, CGPoint second) {
    CGFloat deltaX = second.x - first.x;
    CGFloat deltaY = second.y - first.y;
    return atan2f(deltaY, deltaX);
}

static inline CGPoint RotatePointAroundPoint(CGPoint point, CGPoint origin, CGFloat angle) {
    CGFloat newX = origin.x + (point.x - origin.x) * cos(angle) - (point.y - origin.y) * sin(angle);
    CGFloat newY = origin.y + (point.x - origin.x) * sin(angle) - (point.y - origin.y) * cos(angle);
    return CGPointMake(newX, newY);
}

static inline CGFloat AngleFromVector(CGVector v) {
    return atan2(v.dx, v.dy);
}

static inline CGFloat SpeedFromVector(CGVector vector) {
    CGFloat hyp = sqrt(vector.dx * vector.dx + vector.dy * vector.dy);
    return hyp;
}

static inline CGVector TangentVelocityVectorFromPosition(CGPoint position, CGFloat angle, CGFloat radius) {
    CGFloat tangent = tan(angle) * radius;
    
    CGFloat xMult = position.y > 0 ? -1 : 1;
    CGFloat yMult = position.x > 0 ? 1 : -1;
    
    return CGVectorMake(sin(angle) * tangent * xMult, cos(angle) * tangent * yMult);
}

static inline CGVector VectorFromSpeedAngleAndPosition(CGFloat speed, CGFloat angle, CGPoint position)
{
    CGFloat xMult = position.y > 0 ? -1 : 1;
    CGFloat yMult = position.x > 0 ? 1 : -1;
    CGVector vector = VectorFromSpeedAndAngle(speed, angle);
    return CGVectorMake(vector.dx * xMult, vector.dy * yMult);
}
