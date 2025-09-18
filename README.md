# Advanced Comment Node
Unreal Engine Plugin which gives the developer advanced settings around Group Movement usage.
## Options
### `Comment Nodes Move Behavior`
How moving comment nodes should affect their contents.
  - `Use Node Move Mode`  **(Default)** - Comment node will move how the node is configured . Holding Shift will force content movement as configured.
  - `Always Move Contents` - Always move contents with the comment. Holding Shift Inverts the behavior.
  - `Never Move Contents` - Never move contents, comment box only. Holding Shift Inverts the behavior.

### `Comment Nodes Move Shift Modifier`
###### *Only available when **Move Behavior** is set to default.*
Determines how moving comment nodes should affect their contents when using NodeMoveMode, otherwise Shift will Invert the current override.
- `Force Move Contents` **(Default)** - Holding Shift will force the comment to move by itself, leaving all contained nodes behind.
- `Force Move Group` - Holding Shift will force the comment and all its contained nodes to move together as a group.

<img width="818" height="435" alt="image" src="https://github.com/user-attachments/assets/6be163fa-1e87-4c22-a1a1-22c2ca702c10" />
