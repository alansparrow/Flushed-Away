//
//  FLAViewController.m
//  Flushed Away
//
//  Created by Jonathan on 9/10/13.
//  Copyright (c) 2013 Piglettens, Ltd. All rights reserved.
//

#import "FLAViewController.h"
#import "FLAPlayScene.h"
#import "FLAStartCreditsScene.h"

@interface FLAViewController ()
@property (nonatomic, readonly) SKView *skView;
@end

@implementation FLAViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    self.skView.showsFPS = YES;
    self.skView.showsNodeCount = YES;
    self.skView.showsDrawCount = YES;

    double delayInSeconds = 0.3;
    dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayInSeconds * NSEC_PER_SEC));
    dispatch_after(popTime, dispatch_get_main_queue(), ^(void){
        [self showStartCreditsScene];
    });
}

- (void)showStartCreditsScene
{
    // Create and configure the scene.
    SKScene *scene = [FLAPlayScene sceneWithSize:self.skView.bounds.size];
    scene.scaleMode = SKSceneScaleModeAspectFill;

    // Present the scene.
    [self.skView presentScene:scene];
}

- (BOOL)shouldAutorotate
{
    return YES;
}

- (NSUInteger)supportedInterfaceOrientations
{
    return UIInterfaceOrientationMaskLandscape;
}

- (SKView *)skView
{
    return (SKView *)self.view;
}

@end
