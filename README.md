# sadx-input-mod
sadx-input-mod is a mod for SADX PC that replaces the default DirectInput polling with SDL2 to enable more robust gamepad support. It allows the use of DirectInput and XInput controllers simultaneously.

### What it can do
* Configurable deadzones per analog stick
* Configurable rumble intensity
* Per-controller rumble (vanilla SADX only allows rumble for P1's controller)
* Fixed right analog stick (first person camera bug) for XInput and some DirectInput controllers
* Enables extended Dreamcast buttons C, D, and Z, mapped to LB (PSx L1), Back (PS1-PS3 Select, PS4 Share), and RB (PSx R1) respectively.
* Configurable gamepad controls using SDL controller maps
* Configurable keyboard controls

## Configuration
To configure each controller and/or the keyboard, create a file called `config.ini` in the mod's root folder (`mods/sadx-input-mod`).

### `[Controller N]` section
Where `N` is the controller slot to configure. In official builds, you can use and configure up to 8 controllers.
Configurable controller fields are as follows:

#### Fields
| Field                    | Type        | Range        | Default     | Description |
| ------------------------ | ----------- | ------------ | -----------:| ----------- |
| `DeadzoneL`              | integer     | `0`, `32767` |      `7849` | Analog stick deadzone. |
| `DeadzoneR`              | integer     | `0`, `32767` |      `8689` | Analog stick deadzone. |
| `RadialL`                | boolean     | `0`, `1`     |         `1` | Enables full range of motion on this analog stick. |
| `RadialR`                | boolean     | `0`, `1`     |         `0` | Ditto. If not explicitly configured and [sadx-smooth-cam](https://github.com/SonicFreak94/sadx-smooth-cam) is detected, it is `1` by default. |
| `TriggerThreshold`       | integer     | `0`, `32767` |        `30` | Trigger to digital conversion threshold. |
| `RumbleFactor`           | float       | `0.0`, `1.0` |       `1.0` | Rumble multiplier. Values below 0 or above 1 have no effect. |
| `MegaRumble`             | boolean     | `0`, `1`     |         `0` | Always fire both motors while rumbling, never independently. |

#### Example
```ini
[Controller 1]
DeadzoneL = 4096
DeadzoneR = 4096
RadialR = 1
```

### `[Config]` section
This section allows you to configure general mod settings.

#### Fields
| Field                    | Type        | Range        | Default     | Description |
| ------------------------ | ----------- | ------------ | -----------:| ----------- |
| `Debug`                  | boolean     | `0`, `1`     |         `0` | Enables ingame controller debugging information. |
| `DisableMouse`           | boolean     | `0`, `1`     |         `1` | Disable mouse controls. |

#### Example
```ini
[Config]
Debug = 1
DisableMouse = 0
```

### `[Keyboard]` section
This section allows you to configure keyboard controls. The values are Windows virtual key codes (decimal). Click [here](http://cherrytree.at/misc/vk.htm) for a list of usable keycodes.

#### Fields
| Field                    | Type        | Range        | Default     | Description |
| ------------------------ | ----------- | ------------ | -----------:| ----------- |
| `-leftx`                 | integer     | `0`, `255`   |       `37`  | Move character left. |
| `+leftx`                 | integer     | `0`, `255`   |       `39`  | Move character right. |
| `-lefty`                 | integer     | `0`, `255`   |       `38`  | Move character forward. |
| `+lefty`                 | integer     | `0`, `255`   |       `40`  | Move character backwards. |
| `start`                  | integer     | `0`, `255`   |       `13`  | Start button. |
| `a`                      | integer     | `0`, `255`   |       `88`  | Jump (A button). |
| `b`                      | integer     | `0`, `255`   |       `90`  | Action (B button). |
| `x`                      | integer     | `0`, `255`   |       `65`  | Pick Up (X button). |
| `y`                      | integer     | `0`, `255`   |       `83`  | Whistle (Y button). |
| `lefttrigger`            | integer     | `0`, `255`   |       `81`  | Rotate camera left. |
| `righttrigger`           | integer     | `0`, `255`   |       `87`  | Rotate camera right. |
| `-rightx`                | integer     | `0`, `255`   |       `74`  | Look left. |
| `+rightx`                | integer     | `0`, `255`   |       `76`  | Look right. |
| `-righty`                | integer     | `0`, `255`   |       `73`  | Look up. |
| `+righty`                | integer     | `0`, `255`   |       `77`  | Look down. |
| `leftshoulder`           | integer     | `0`, `255`   |       `67`  | C button. |
| `rightshoulder`          | integer     | `0`, `255`   |       `66`  | Z button. |
| `back`		           | integer     | `0`, `255`   |       `86`  | D button. |
| `leftstick`	           | integer     | `0`, `255`   |       `69`  | Center camera on character. |
| `rightstick`	           | integer     | `0`, `255`   |       `160` | Imitate analog half-press. |
| `dpup`		           | integer     | `0`, `255`   |       `104` | D-Pad up (menus). |
| `dpdown`		           | integer     | `0`, `255`   |       `98`  | D-Pad down (menus). |
| `dpleft`		           | integer     | `0`, `255`   |       `100` | D-Pad left (menus). |
| `dpright`		           | integer     | `0`, `255`   |       `102` | D-Pad right (menus). |

#### Example
```ini
[Keyboard]
-leftx=37
+leftx=39
+lefty=40
-lefty=38
start=13
a=88
b=90
x=65
y=83
lefttrigger=81
righttrigger=87
-rightx=74
+rightx=76
-righty=73
+righty=77
leftshoulder=67
rightshoulder=66
back=86
leftstick=69
rightstick=160
dpup=104
dpdown=98
dpleft=100
dpright=102
```