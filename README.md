# Fallout3 door randomizer (arbidoor)

This is a FOSE plugin to randomize doors for purely Fallout 3. It aims for
all doors to be reachable without the use of console, glitches or speedrun
tricks, although some are tricky and require unintended clever climbing.

It creates a '.arb' 'seed file' from your configuration tied to the
player-character-name (e.g. todd.arb). If the active DLCs change and
the total number of doors mismatches the '.arb' seed file, then the
randomizer may silently quit, and doors will not be random.

To generate a new seed, you can move, rename, or delete the '.arb' file for your
character. You can make backups or share seed files as long as the plugin
versions and config options match.

Quest locked doors and any that change due to scripts are not included.

# Installation

Make sure you have Fallout 3 version 1.7.0.3.

GOG is at this version, Steam requires a downpatch
[Fallout Anniversary Patcher](https://www.nexusmods.com/fallout3/mods/24913).

Assuming you have [FOSE](https://www.nexusmods.com/fallout3/mods/8606) installed.

- Put `arbidoor.dll` in `Fallout 3\Data\fose\plugins`

- Put `arbidoor.ini` in `Fallout 3\` (alongside fose_loader and Fallout3 exe files)

Seed '.arb' files will be in `Fallout 3\` (alongside fose_loader and Fallout 3 exe files)

If this does not seem to work, make sure:

- DLCs you have configured are enabled and active

- fose.log says `arbidoor` was loaded correctly

- try to rename `.arb` file and see if a new one works

# Config arbidoor.ini

Pretty self explanatory, but some lengthier explanations of
[arbidoor.ini](./arbidoor.ini)

### General options

#### - enabled

Can be toggled during gameplay. A save-load will un/randomize doors with
the player's seed file.

#### - sane_doors

Pairs doors 1<>1, so you can go back the way you came. This also tries
to make sure all doors are reachable.

### Optional areas

#### - fo3base

The main world map and vanilla game. (excluding...)

#### - vault101child

You're not supposed to come back here, there's only a few doors, and
you'd probably miss out on leaving the vault proper during 'ESCAPE!'

The vault also gets switched out for the Homefront quest later in the game.
This is done by changing the cave<>outside door, effectively making this
a 1-way.

#### - tranquility

Having tranquility enabled allows for a nice hub of doors. But whatever
you do, **DO NOT USE THE EXIT DOOR**. Using the 'failsafe exit' before
sitting in the chair **WILL SOFTLOCK** you as a child. The box with all your
stuff in it (and the door that goes to the sim) are OOB in the 112 cell. Not
only that, but going into 112 after having been in Tranquility will take all
of your stuff, and it will not be in the box. So plan ahead!

If you want to route getting to 112, sit in the chair, then make your way
as a kid to wherever the quest objectives are, which may be anywhere or dead
if you're doing the whole quest line, WITHOUT PIPBOY, and THEN take the exit
door, you should be fine.

The easiest way to do this is to just avoid the chair and exit door altogether.
Again, make sure you drop your gear if you went into Tranquility first and THEN
go into 112 to talk to dad once you're done.

#### - vault87 (and friends)

There are a few main quests that do not have markers. Vault 87 being
a big part of that. Up to murder pass you have something to go off of.
But after that it kind of just lets you be, because it's a linear and
straight forward path. For randomized doors, this is not the case and
it's a royal pain to find where to go.

Having these doors static for allows easy completion of the main quest.

Citadel and Jefferson main entrances are also included with this.

Citadel - similarly doesn't give a quest marker because you just opened
the gate, so obviously you should walk in to talk to Lyons and Li.

>Note: you CAN access Citadel gate by going around back. This can be
done with a very specific OOB route, or by clipping.

Jefferson - when you go to find the valve inside pipes, they are
actually outside in the main world. The quest marker points you there,
and you can use tricks to not need the pipes, but this makes it
easier than having to go inside multiple places and hope the marker
changes to the actual gift-shop entrance, mark it yourself, then hunt
it down.

This is good to enable if you want a challenge :)

#### - ravenrock

Going through the front door works 100% fine in vanilla...however...
There are invisible walls and doors are locked due to not being in
the right quest stages. Not sure how going back here works when the
quest is complete.

#### - anchorage

The whole sim is full of softlocks and 1-way doors. You would probably
never know it because why would you go back? But multiple areas will
go through a door, only to have a holo-door behind you and the real
door behind the wall. In some areas, like when Montgomery comes out of
the pipes, a holo-door closes behind you and if he's not at the expected
quest stage, you're softlocked. The commander's tent after the artillery
guns will softlock if you didn't do everything before that. The end door
before the fight isn't supposed to be gone through the opposite way,
and either way it will disable player controls.

So the only doors included here are the few that touch the main map and
'real' world.

#### - pitt

Some doors are quest locked, mainly everything from the handcart to the
front gate, and a door in the Mill.

The handcart is a 1-way and teleports you to the start of the DLC.

The gate changes out when you complete the DLC so you can use it.

Midea can get stuck if the path to her hut is blocked.

Some of the doors for 1 of the ending's of Pitt are also quest locked.


#### - pointlookout

Some of the main quests have locked doors
(bog, seatub, under lighthouse, chinese spy hatch)

Since this has a decent sized map and plenty of doors, it is the
best for a randomizer.

#### - zeta :(

Nothing here is usable. Teleporters are turned off willy-nilly.
Entering the DLC only has 1 door and you have to hope it's a good one.
Half way through normal gameplay you are locked out of half the DLC,
which is a poor design choice on top of being bad for a randomizer.
Then the second half gets cut off when you beat the DLC. So if any
crucial or useful doors were linked here, you will lose them because
you have to beat the DLC to leave.

There were a few dev rooms that are really interesting too. They're in
doors.h, check them out with `player.moveto <doorid>` if you get a chance.
Sadly, none of it can be used because the whole thing becomes inaccesible
for no good reason :(

#### - brokensteel

The airforce base is the main area used here. A lot of the post-game
quests are locked until you beat the game because they touch the world
map. And then a lot of the end stuff like presidential metro is locked
or has 1-ways like the train. The doors are right under it, but when
they randomize the train ignores them.

# Misc notes, areas and quest issues

You can check doors.h and cell*.h files for more doors and notes.

Some more important items:

#### Map marker

This works surprisingly well. It may not take you the best way, but it should
take you the right way. Routes change depending on where you are, either on the
map or per-cell. If you fast travel or go inside a door, you may be able to find
a better path to where you're going.

Since the doors are replaced on save-loads, if you are focused on a door when
loading, the text will be briefly incorrect. Similarly for the map marker, you
will have to go into another door or toggle active quest for it to update after
loading.

#### Pits / Ledges / bridges

There are some shared cells and outside locations that have unreachable,
clearly world-building intended uses. Constantine and some other areas
have bridges between buildings. There are satellites and roofs on the map
where you would never be able to get to the top of and a door up there
would require the ~ console to get to.

These should be covered in sane-door logic, and there are a few special
locations where you can climb even though it's not intended :) but if
you find any unreachables that could make a door inaccessible, please
open a issue or pull request. (Clicking on the door in ~ console to get the
ID for the problem door. The text "door" should show up. A map pic, screenshot,
or save file will help too.)

#### Dev areas

There's a few secrets. Sadly not all of them are included as some drop
you in the middle of a random spot that doesn't make sense, with no door
to go back through.

#### Washington monument

The elevator doors are OOB but do not get used by the elevator itself.
No matter what you will be teleported to the same areas.

The front is behind a quest locked terminal, so there's no point in
trying to make it behave like a 1-way just for a potential shortcut
to the mall where you will be able to fast travel anyway.

#### Tenpenny

If you have ever done Roy's quest, you may have seen the alternate
version of Tenpenny. This has some 'shared cells' and doors, so some
doors like the front door and the generator room (waringtonstation03)
become 1-ways if randomized, as the game changes them out similar to 101.

The front and generator doors will always take you to the active Tenpenny doors,
which means you'd have to circle around to however you got to alternate Tenpenny.
But that's a small price for the other doors you usually can only see for
3 in-game days.

#### Controls disabled

Some areas, scripts, quests, NPCs seem to disable player controls and require
the console command `enableplayercontrols`. I think this may be related to
dialog like interacting with a Dave Escort outside of Republic of Dave, or
after you have already made them hostile.

#### NPCs and quests

As mentioned above, this messes with AI pathing. Some NPCs will be in the middle
of nowhere. I've seen Evan King walk over a mine, and multiple NPCS in the
middle of the wasteland.

Some NPCs need a little nudge by going to the correct activators or spots to
progress the quest. In some cells, like the scientist making their way to
Jefferson, certain layouts or pathing may stall them in place. Li gets a bit
lost at the end of Waters Of Life and needs the player to go in-and-out of the
Taft sewer next to the Citadel.

Some quests may require game and/or quests/stage knowledge, best to make safety
saves if you're unsure.
It can also outright end some quest
(e.g. Evan King is the only way to start the Family quest).

The worst has been...

#### Vanilla end game (Take it back!)

This quest is buggy on its own. Speedruns have issues with it too.
If you do not have Sarah with you to finish the quest, then Broken
Steel will not start.

Sarah does not always come into the rotunda. You have to go to Jefferson,
and then exit and talk to her, or maybe even go to where she is marked on
the map and get her to follow you. Then most likely have to go into the
randomized door in Jefferson gift-shop to the rotunda (that goes somewhere
else). Then find the rotunda and hope she spawns after talking to Autumn.
If Autumn doesn't talk to you on his own, she will probably not say her
lines about the purifier. This can take a few tries to get right. Me and
others have had this issue.

Or, maybe that's just luck :) The quest is buggy, the game is buggy, and
moving doors around isn't doing it any favors.

# Thanks

Thanks to everyone who helped test and ChaseDel for the thumbnail!