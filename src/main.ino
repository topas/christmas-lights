#include <WS2812FX.h>
#include "OneButton.h"

#define LED_COUNT 50
#define LED_PIN 6

#define WHITE_COLOR 0xFFFFFFFF
#define VIOLET_COLOR 0x7F00FF
#define BLUE_COLOR 0x0050FF
#define GREEN_COLOR 0x00FF00
#define YELLOW_COLOR 0xFFF000
#define ORANGE_COLOR 0xFF7400
#define RED_COLOR 0xFF0000
#define PINK_COLOR 0xFF0082

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

OneButton whiteButton(2, true);
OneButton violetButton(3, true);
OneButton blueButton(4, true);
OneButton greenButton(5, true);
OneButton yellowButton(7, true);
OneButton orangeButton(8, true);
OneButton redButton(9, true);
OneButton pinkButton(10, true);
OneButton brightnessButton(14, true);
OneButton modeButton(16, true);

#define BRIGHTNESS_COUNT 5
int brightnessValues[BRIGHTNESS_COUNT] = {8, 32, 64, 128, 255};
int brightnessIndex = 1;

#define MODES_COUNT 13
int modeValues[MODES_COUNT] = {
    FX_MODE_STATIC,
    FX_MODE_BREATH,
    FX_MODE_RANDOM_COLOR,
    FX_MODE_MULTI_DYNAMIC,
    FX_MODE_RAINBOW_CYCLE,
    FX_MODE_SCAN,
    FX_MODE_DUAL_SCAN,
    FX_MODE_RUNNING_LIGHTS,
    FX_MODE_TWINKLE,
    FX_MODE_TWINKLE_RANDOM,
    FX_MODE_SPARKLE,
    FX_MODE_FIREWORKS,
    FX_MODE_FIRE_FLICKER};

int modeIndex = 0;

void onWhiteButtonClick()
{
    Serial.println("White button.");
    ws2812fx.setColor(WHITE_COLOR);
}

void onVioletButtonClick()
{
    Serial.println("Violet button.");
    ws2812fx.setColor(VIOLET_COLOR);
}

void onBlueButtonClick()
{
    Serial.println("Blue button.");
    ws2812fx.setColor(BLUE_COLOR);
}

void onGreenButtonClick()
{
    Serial.println("Green button.");
    ws2812fx.setColor(GREEN_COLOR);
}

void onYellowButtonClick()
{
    Serial.println("Yellow button.");
    ws2812fx.setColor(YELLOW_COLOR);
}

void onOrgangeButtonClick()
{
    Serial.println("Orange button.");
    ws2812fx.setColor(ORANGE_COLOR);
}

void onRedButtonClick()
{
    Serial.println("Red button.");
    ws2812fx.setColor(RED_COLOR);
}

void onPinkButtonClick()
{
    Serial.println("Pink button.");
    ws2812fx.setColor(PINK_COLOR);
}

void onBrightnessButtonClick()
{
    Serial.println("Brightness button.");
    brightnessIndex = (brightnessIndex + 1) % BRIGHTNESS_COUNT;
    setBrightness();
}

void setBrightness()
{
    ws2812fx.setBrightness(brightnessValues[brightnessIndex]);
}

void setMode()
{
    ws2812fx.setMode(modeValues[modeIndex]);
}

void onModeButtonClick()
{
    Serial.println("Mode button.");
    modeIndex = (modeIndex + 1) % MODES_COUNT;
    setMode();
}

void setup()
{
    ws2812fx.init();
    setBrightness();
    ws2812fx.setSpeed(1000);
    ws2812fx.setColor(WHITE_COLOR);
    setMode();
    ws2812fx.start();

    whiteButton.attachClick(onWhiteButtonClick);
    violetButton.attachClick(onVioletButtonClick);
    blueButton.attachClick(onBlueButtonClick);
    greenButton.attachClick(onGreenButtonClick);
    yellowButton.attachClick(onYellowButtonClick);
    orangeButton.attachClick(onOrgangeButtonClick);
    redButton.attachClick(onRedButtonClick);
    pinkButton.attachClick(onPinkButtonClick);
    brightnessButton.attachClick(onBrightnessButtonClick);
    modeButton.attachClick(onModeButtonClick);
}

void loop()
{
    whiteButton.tick();
    violetButton.tick();
    blueButton.tick();
    greenButton.tick();
    yellowButton.tick();
    orangeButton.tick();
    redButton.tick();
    pinkButton.tick();
    brightnessButton.tick();
    modeButton.tick();

    ws2812fx.service();
}
