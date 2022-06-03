//
//

#import <UIKit/UIKit.h>

@class JDStatusBarView;
@class JDStatusBarStyle;

NS_ASSUME_NONNULL_BEGIN

typedef void (^ _Nullable JDStatusBarNotificationViewControllerDismissCompletion)(void);

@protocol JDStatusBarNotificationViewControllerDelegate
- (void)animationsForViewTransitionToSize:(CGSize)size;
- (void)didDismissStatusBar;
@end

@interface JDStatusBarNotificationViewController : UIViewController

@property (nonatomic, strong, readonly) JDStatusBarView *statusBarView;
@property (nonatomic, weak) id<JDStatusBarNotificationViewControllerDelegate> delegate;

- (instancetype)initWithStyle:(JDStatusBarStyle *)style;

- (JDStatusBarView *)showWithStatus:(NSString *)status style:(JDStatusBarStyle *)style;

- (void)dismissAfterDelay:(NSTimeInterval)delay
               completion:(JDStatusBarNotificationViewControllerDismissCompletion)completion;

- (void)dismissWithDuration:(CGFloat)duration
                 completion:(JDStatusBarNotificationViewControllerDismissCompletion)completion;

@end

NS_ASSUME_NONNULL_END
