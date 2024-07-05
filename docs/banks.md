# Banks
As a high level overview, banks 80-8F are responsible for the underlying game engine and handles many things such as the game loop, game states,
menus, effects, the overworld, and more. Banks 90-9F are responsible for handling Samus physics and interactions, including her movement,
her collision, her projectiles, and more. Banks A0-B3 are responsible for handling the game's enemies, including their AI, movement, interactions,
and more. The rest of the banks mainly contains data, such as graphics, palettes, level data, and music.

## Bank 80
Bank 80 handles many of the core engine routines, such as:
- Register transfers
- Transfers between RAM, VRAM, OAM, and CGRAM
- Music and sound processing
- Interrupt handling
- HUD logic and drawing
- Timer processing
- Scrolling
- Decompression

## Bank 81
Bank 81 handles much of the processing, such as:
- Save data
- Map data
- Spritemap processing
- Menu processing

## Bank 82
Bank 82 handles the game loop, including:
- Initialization
- Game state processing
- Title screen demos
- Menu objects
- Pause menu
- Minimap
- Door transitions
- Loading room backgrounds

## Bank 83
Bank 83 mainly contains data, including:
- Room FX definitions
- Door header definitions
- Area palette and FX object lists

## Bank 84
Bank 84 handles PLMs (Post Level Modifications), which are used to modify the rooms after they have been loaded. This includes:
- PLM setups
- PLM pre-instructions
- PLM instructions
- PLM entries
- PLM instruction lists
- PLM draw instructions

## Bank 85
Bankn 85 handles message boxes, and is responsible for setting up and displaying the message boxes.

## Bank 86
Bank 86 handles enemy projectiles, which are used to handle the projectiles that enemies shoot or eject.

## Bank 87
Bank 87 handles animated tiles, which are used to animate tiles in the game.

## Bank 88
Bank 88 is responsible for HDMA (Horizontal Direct Memory Access), which is used to transfer data from ROM to VRAM during H-blank.
This is responsible for many visual effects, such as:
- Power bomb explosions
- Wide light effects (x-ray scope, Mother Brain rainbow beams, eye beams)
- Parallax scrolling (used for scrolling sky backgrounds)
- Liquids
- Fireflea lighting
- Haze
- Gradients
- Wavy effects

## Bank 89
Bank 89 is mostly data for item PLM graphics, power bomb explosion tables, and palette blends. It is also responsible for
setting up room FX.

## Bank 8A
Bank 8A contains tilemaps for FX and scrolling skies.

## Bank 8B
Bank 8B handles the non-gameplay components, such as the title screen, intro cutscenes, and credits.

## Bank 8C
Bank 8C mainly contains tilemaps, palettes, and instruction lists for the non-gameplay components.

## Bank 8D
Bank 8D contains many of the enemy projectile tilemaps used in bank 86. Beyond that, it handles the FX palettes, including:
- Pre-instructions
- Instructions
- Instruction lists
- FX palette object definitions

## Bank 8E
Bank 8E contains data for the main menu tiles and palettes.

## Bank 8F
Bank 8F contains the logic and data for the room metadata, which includes:
- Room header definitions
- Room states
- Room state header definitions
- Door lists
- Scroll data
- PLM scroll data
- Room PLM population data
- Library background header definitions
- Room setup and main functions
- Door functions

## Bank 90
Bank 90 handles Samus physics, including:
- Samus movement
- Samus camera scrolling
- Projectile physics and collision
- Samus moves such as shinespark, knockback, bomb jumping, and more
- Samus state handler
- Samus draw handler
- Samus command functions

## Bank 91
Bank 91 handles other Samus functions, such as:
- Samus pose and pose transition handling
- Samus demo movement
- Samus x-ray movement

## Bank 92
Bank 92 handles Samus animations and contains the animation tilemap and metadata for Samus.

## Bank 93
Bank 93 handles projectiles, including initialization and drawing.

## Bank 94
Bank 94 handles block collision, including:
- Samus collision with blocks
- Projectile collision with blocks
- Grapple collision

## Bank 95 - Bank 99
Banks 95-99 contains data, such as tiles and tilemaps, for menus and other non-gameplay components.

## Bank 9A
Bank 9A contains data, such as tiles and tilemaps, for the Samus' beams and map.

## Bank 9B
Bank 9B is resposible for Samus' death sequence and grapple beam handling.

## Banks 9C - 9F
Banks 9C-9F contain tile data for Samus.

## Bank A0
Bank A0 handles enemy processing, including:
- Loading enemy data
- Enemy collision
- General enemy functions

## Bank A1
Bank A1 contains the enemy population for each room.

## Bank A2
Bank A2 contains enemy AI and instructions for the following enemies:
- Bouncing gooball (Boyon)
- Mini-crocomire (unused)
- Maridia beyblade turtle (Kame (mother) and Kame (child))
- Thin hopping blobs (Puyo)
- Spike shooting plant (Cacatac)
- Maridia spikey shell (Owtch)
- Gunship
- Flies (Mellow)
- Norfair erratic fireball
- Lavaquake rocks
- Rinka
- Rio (Reo)
- Norfair lava-jumping enemy (Puromi)
- Norfair rio (Geruta)
- Lower Norfair rio (Holtz)
- Maridia large indestructible snail
- High-rising slow-falling enemy (Choot)
- Gripper
- Jet powered ripper (Ripper 2)
- Ripper
- Lava seahorse (Dragon)
- Shutters

## Bank A3
Bank A3 contains enemy AI and instructions for the following enemies:
- Waver
- Metal skree (Metaree)
- Fireflea
- Maridia fish (Skultera)
- Elevator
- Crab (Sciser)
- Slug (Zero)
- Platforms
- Roach
- Mochtroid
- Sidehoppers
- Maridia refill candy (Zoa? Menu?)
- Norfair slow fireball
- Bang (unused)
- Skree
- Maridia snail (Yard)
- Reflec (unused)
- Wrecked Ship orange zoomer (Geemer)
- Big eye bugs / zoomer (Geemer)
- Creepy crawlies
- Metroid

## Bank A4
Bank A4 contains enemy AI and instructions for Crocomire.

## Bank A5
Bank A5 contains enemy AI and instructions for Draygon and Spore Spawn.

## Bank A6
Bank A6 contains enemy AI and instructions for the following enemies:
- Boulder
- Spikey platform
- Fire geyser
- Nuclear waffle
- Fake Kraid
- Ridley
- Ceres steam
- Ceres door
- Zebetites

## Bank A7
Bank A7 contains enemy AI and instructions for Kraid, Phantoon, and Dachora.

## Bank A8
Bank A8 contains enemy AI and instructions for the following enemies:
- Mini-Draygon (Evir)
- Morph ball eye
- Funes
- Wrecked Ship ghost (Covern)
- Yapping maw
- Kago
- Norfair lava creature (Maddollite?)
- Beetom
- Maridia floater (Powamp?)
- Wrecked Ship robot (Workrobot)
- Maridia puffer (Powamp?)
- Walking lava seahorse (Alcoon)
- Wrecked Ship orbs (Atomic)
- Wrecked Ship spark
- Blue Brinstar face block
- Kihunter

## Bank A9
Bank A9 contains enemy AI and instructions for the following enemies:
- Mother Brain
- Shitroid (Giant Baby Metroid)
- Dead monster corpse

## Bank AA
Bank AA contains enemy AI and instructions for the following enemies:
- Torizo
- Tourian entrance statue
- Shaktool
- n00b tube cracks (Maridia tube cracks)

## Banks AB - AC
Banks AB-AC contain enemy tile data.

## Bank AD
Bank AD contains enemy tile data, as well as extra functions for Mother Brain rainbow beam, and Mother Brain and
Shitroid (Baby Metroid) palette handling.

## Banks AE - B1
Banks AE-B1 contain enemy tile data.

## Bank B2
Bank B2 contains enemy AI and instructions for wall, walking, and ninja Space Pirates.

## Bank B3
Bank B3 contains enemy AI and instructions for the following enemies:
- Spinning turtle eye (unused)
- Brinstar red/green pipe bug (Zebbo/Zeb)
- Norfair pipe bug (Gamet)
- Brinstar yellow pipe bug (Geega?)
- Botwoon
- Escape etecoon
- Escape dachora

## Banks B4
Bank B4 is responsible for debug handling, sprite object handling, and enemy data such as names, weakness, and drops.

## Bank B5
Bank B5 contains tilemaps for each area map.

## Bank B6
Bank B6 contains data for the pause menu, such as tiles, tilemaps, and palettes.

## Bank B7
Bank B7 contains enemy tile data.

## Bank B8
Bank B8 does not contain any code, but is used for temporarily storing data

## Banks B9 - BA
Banks B9-BA contains compressed data for CRE tiles, CRE tile tables, and backgrounds.

## Banks BA - C1
Banks BA-C1 contain compressed data for tileset tiles.

## Banks C1 - C2
Banks C1-C2 contain compressed data for tile table tilesets.

## Banks C2 - CE
Banks C2-CE contain compressed data for palettes and level data.

## Banks CF - DE
Banks CF-DE contain music data and contains the SPC engine.

## Bank DF
Bank DF contains unused music data.