//
//  BNDBinding.h
//  Bindings
//
//  Created by Ryan Davies on 17/02/2013.
//  Copyright (c) 2013 Ryan Davies. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BNDTriggerDelegate.h"
@protocol BNDProperty, BNDTrigger;

/** Defines a relationship between a property on the _source_ and another on the _destination_. Triggers are used to notify the binding when the source's value changes. */
@interface BNDBinding : NSObject <BNDTriggerDelegate>

/** Initializes a binding.
 @param sourceProperty The property to observe. See @protocol(BNDProperty).
 @param destinationProperty The property to apply changes to. See @protocol(BNDProperty).
 @return An initialized instance of BNDBinding. */
- (id)initWithSourceProperty:(id <BNDProperty>)sourceProperty destinationProperty:(id <BNDProperty>)destinationProperty;

/** @param trigger The trigger to add the binding. */
 - (void)addTrigger:(id <BNDTrigger>)trigger;

/** @param trigger The trigger to remove from the binding. */
 - (void)removeTrigger:(id <BNDTrigger>)trigger;

/** Binds the destination's property to the source's. */
- (void)bind;

/** Releases the binding, allowing source's value to change without being applied to the destination. */
- (void)unbind;

/** The property to be observed for changes. */
@property (strong, nonatomic, readonly) id <BNDProperty> sourceProperty;

/** The property which changes are applied to. */
@property (strong, nonatomic, readonly) id <BNDProperty> destinationProperty;

@end
