# Main Menu Plugin
Clone this repo directly to your plugins folder. You don't have to take the plugins out of the MainMenu folder

This plugin comes with an example map, `L_MainMenu`, inside the main menu folder. When you play it, it should load the main menu from the `BP_DefaultMainMenuConfigurator`.

To make your own main menu, subclass `BP_DefaultMainMenuConfigurator` or the `MainMenuConfigurator` class and then set your Main Menu Configurator class in the Project Settings -> Game -> Main Menu Settings.

Once you've done that, you can use the main menu widget anywhere in your project.