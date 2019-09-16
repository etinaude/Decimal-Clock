# Clock

## This is a CPP programme which runs on ardinos

### Why

I dont like the second. It is (debatably) the the worst metric base unit of mesurement, it is used due to purely historic reasons, other units are based directly off pysical properties or a multiple of 10 of a physical property.

many others have thought of this and many other people have made [decimal time systems](https://en.wikipedia.org/wiki/Decimal_time), I suggest looking up french revolution time or [swatch internet time](https://en.wikipedia.org/wiki/Swatch_Internet_Time).

so I have created a clock for displaying time in both 24hr time and decimal time so people understand the easier system.

## Standard 24hr time

|Stnadard-|Hours|Minutes|Seconds|
|----------:|-----------------| ------------:|-------------:|
|1 Day =    | 24    | 1440|86 400|
|1 Hour =   |-| 60| 3600|
|1 Minute = |-|-| 60

This is highly illogical since the devisor is not a power of 10 nor a constant for each increment.

## Decimal time

|Decimal -|Hours|Minutes|Seconds|
|----------:|----| ------------:|-------------:|
|1 Day =    | 10 | 1000|100 000 |
|1 Hour  =|-| 100      | 10 000|
|1 Minute = |-|-| 100      |  

## 24 to decimal conversions

|std/dec|Hours|Minutes|Seconds|
|----------:|-------| -------:|-------------:|
|1 Hour =   | 0.41| 41.67| 4166.67|
|1 Minute = | 0.0069| 0.69| 69.44|
|1 Second = | 0.00012| 0.012| 1.16|

## Decimal to 24 conversions

|dec/std|Hours|Minutes|Seconds|
|----------:|-------| -------:|-------------:|
|1 Hour =   | 2.40| 144.00| 8640|
|1 Minute = | 0.024| 1.44| 86.40|
|1 Second = | 0.0024| 0.014| 0.86|

this shows a decimal second is shorter than a standard one giving more acuracy while a minute and an hour is longer.

the CPP code runs on adunio nano and displays both standard and decimal time.
