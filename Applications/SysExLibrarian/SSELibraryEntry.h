#import <OmniFoundation/OFObject.h>
#import <Cocoa/Cocoa.h>

@class BDAlias;
@class SSELibrary;


@interface SSELibraryEntry : OFObject
{
    SSELibrary *nonretainedLibrary;

    NSString *name;
    BDAlias *alias;

    // Caches of file information
    NSString *manufacturer;
    NSNumber *sizeNumber;
    NSNumber *messageCountNumber;
    struct {
        unsigned int isFilePresent:1;
        unsigned int hasLookedForFile:1;
    } flags;
}

- (id)initWithLibrary:(SSELibrary *)library;
- (id)initWithLibrary:(SSELibrary *)library dictionary:(NSDictionary *)dict;

- (SSELibrary *)library;

- (NSDictionary *)dictionaryValues;

- (NSString *)path;
- (void)setPath:(NSString *)value;

- (NSString *)name;
- (void)setName:(NSString *)value;
- (void)setNameFromFile;
- (BOOL)renameFileTo:(NSString *)newFileName;

- (NSArray *)messages;

// Derived information (comes from messages, but gets cached in the entry)

- (NSString *)manufacturer;
- (NSNumber *)size;
- (NSNumber *)messageCount;
- (BOOL)isFilePresent;
- (BOOL)isFilePresentIgnoringCachedValue;

- (BOOL)isFileInLibraryFileDirectory;

@end

// Notifications
extern NSString *SSELibraryEntryNameDidChangeNotification;