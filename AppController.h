#import <Cocoa/Cocoa.h>
//#import <IOBluetooth/IOBluetooth.h>
//#import <IOBluetoothUI/IOBluetoothUI.h>
#import <IOBluetoothUI/objc/IOBluetoothDeviceSelectorController.h>

int thisVersionMajor = 1;
int thisVersionMinor = 6;

typedef enum _BPStatus {
	InRange,
	OutOfRange
} BPStatus;

@interface AppController : NSObject <NSApplicationDelegate, NSUserNotificationCenterDelegate>
{
	IOBluetoothDevice *device;
	NSTimer *timer;
	BPStatus priorStatus;
	NSStatusItem *statusItem;
  bool notify;
	
	NSImage *outOfRangeImage;
	NSImage *outOfRangeAltImage;
	NSImage *inRangeImage;
	NSImage *inRangeAltImage;
	
    IBOutlet id checkUpdatesOnStartup;
    IBOutlet id deviceName;
    IBOutlet id inRangeScriptPath;
    IBOutlet id monitoringEnabled;
    IBOutlet id outOfRangeScriptPath;
    IBOutlet id prefsWindow;
    IBOutlet id progressIndicator;
    IBOutlet id runScriptsOnStartup;
    IBOutlet id timerInterval;
    IBOutlet id enableNotifications;
}

// AppController methods
- (void)createMenuBar;
- (void)userDefaultsLoad;
- (void)userDefaultsSave;
- (BOOL)isInRange;
- (void)menuIconInRange;
- (void)menuIconOutOfRange;
- (void)runInRangeScript;
- (void)runOutOfRangeScript;
- (void)startMonitoring;
- (void)stopMonitoring;


// UI methods
- (IBAction)changeDevice:(id)sender;
- (IBAction)checkConnectivity:(id)sender;
- (IBAction)checkForUpdates:(id)sender;
- (IBAction)donate:(id)sender;
- (IBAction)enableMonitoring:(id)sender;
- (IBAction)inRangeScriptChange:(id)sender;
- (IBAction)inRangeScriptClear:(id)sender;
- (IBAction)inRangeScriptTest:(id)sender;
- (IBAction)outOfRangeScriptChange:(id)sender;
- (IBAction)outOfRangeScriptClear:(id)sender;
- (IBAction)outOfRangeScriptTest:(id)sender;
- (IBAction)showWindow:(id)sender;
- (IBAction)showInRangeNotification:(id)sender;
- (IBAction)showOutRangeNotification:(id)sender;

@end
