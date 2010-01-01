#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#include "puzzles.h"

@class PuzzlesFrontEnd, PuzzlesDrawingView;

struct frontend {
    PuzzlesFrontEnd *object;
    PuzzlesDrawingView *drawingView;
};

@interface PuzzlesFrontEnd : UIViewController<UIActionSheetDelegate> {
    frontend frontend_wrapper;
    const game *myGame;
    midend *myMidend;

    NSTimer *timer;
    struct timeval last_time;
    BOOL wasTiming;

    PuzzlesDrawingView* drawingView;
    UILabel *statusLabel;
    NSArray *configurationActions;

    PuzzlesDrawingView *puzzleView;
    BOOL gameParamsChanged;
}

@property (nonatomic, retain) IBOutlet PuzzlesDrawingView *puzzleView;
@property (nonatomic, retain) IBOutlet UILabel *statusLabel;

- (id)initWithGame:(const game*)aGame;

+ (void)randomSeed:(void**)randseed size:(int*)randseedsize;
+ (void)fatal:(NSString*)format;

- (void)defaultColour:(float*)output;
- (void)activateTimer;
- (void)deactivateTimer;

- (void)setStatusText:(NSString*)status;

- (NSArray*)configurationActions;
- (void)showConfigureMenu;

- (IBAction)undo:(id)sender;
- (IBAction)redo:(id)sender;
- (IBAction)restart:(id)sender;
- (IBAction)new:(id)sender;

- (void)gameParamsChanged;

@end
