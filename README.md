<a name="readme-top"></a>

<!-- PROJECT SHIELDS -->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]



<!-- PROJECT LOGO -->
<br />
<div align="center">

<h3 align="center">
IF2210 Pemrograman Berorientasi Objek</h3>

  <p align="center">
    Tugas Besar 1: Kelola Kerajaan Bersama Labpro
    <br />
    <a href="https://github.com/ValentinoTriadi/Tubes1_OOP"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/ValentinoTriadi/Tubes1_OOP">View Demo</a>
    ·
    <a href="https://github.com/ValentinoTriadi/Tubes1_OOP/issues">Report Bug</a>
    ·
    <a href="https://github.com/ValentinoTriadi/Tubes1_OOP/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#command-and-usage">Usage</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

This project is a simple simulation game developed in C++ for King Bondowoso, who seeks to evaluate Queen Roro's capabilities in managing his kingdom. The game incorporates Object-Oriented Programming (OOP) principles such as Inheritance and Polymorphism, Exception Handling, Function and Operator Overloading, Abstract Classes and Virtual Functions, and Generic Classes. It also utilizes the Standard Template Library (STL), specifically Vector and Map, crucial for data structures and gameplay mechanisms. The simulation includes managing animals, plants, and their products, along with validation for storage slots and capacity. Additionally, it implements functionality to compare and add buildings and items to storage. The game aims to provide an interactive experience tailored to the unique characteristics of Bondowoso's kingdom, allowing him to assess Roro's managerial skills effectively.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With

* ![C++](https://img.shields.io/badge/-c++-black?logo=c%2B%2B&style=social)


<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started


### Prerequisites


- Operating System: Linux, WSL (Windows Subsystem for Linux), or macOS
- Compiler: g++ version 17 or higher
- CMake: Installed on the system

To install CMake on Linux or macOS, follow these steps:

1. Linux (Ubuntu/Debian):
    ```bash
        sudo apt-get update
        sudo apt-get install cmake
    ```
2. macOS (Homebrew):
    ```bash
    brew install cmake
    ```

Ensure that after installation, CMake is available in your system's PATH so that it can be invoked from the command line. Once CMake is installed, you can proceed to build and run the program


### Installation

1. Clone the repo
   ```bash
   git clone https://github.com/ValentinoTriadi/Tubes1_OOP

    ```
2. Build makefile using CMake
    ```bash
    cd src
    cmake ./CMakeList.txt
3. Build binary file
    ```bash
    make
    ```
4. Run the program
    ```bash
    ./Tubes1_OOP
    ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- USAGE EXAMPLES -->
## Command and Usage

1.  Next
    - Roles: All roles
    - Description: Signifies that a player does not want to take any action, passing the turn to the next player. Each time "Next" is executed, the age of all plants increases by 1.
2.  Cetak Penyimpanan
    - Roles: All roles
    - Description: Prints the storage owned by a specific role.
3.  Pungut Pajak
    - Roles: Mayor
    - Description: The mayor collects taxes from each player according to their wealth level. Display the details of tax collection sorted in descending order of tax amount. If there are players with the same tax amount, sort them lexicographically.
4.  Cetak Ladang dan Cetak Peternakan
    - Roles: Farmer, Rancher
    - Description: Displays the current condition of the player's field. Land tiles in the field are filled with codes of planted crops (for farmers) or codes of animals living in the barn tiles (for ranchers). To distinguish between ripe crops and animals, the codes will be printed in different colors.
5.  Tanam
    - Roles: Farmer
    - Description: Plants crops from storage into the player's field.
6.  Ternak
    - Roles: Rancher
    - Description: Raises animals from storage by placing them in one of the player's barn tiles.
7.  Bangun Bangunan
    - Roles: Mayor
    - Description: Constructs buildings according to the recipe specified in the configuration. The mayor can only build buildings if they have sufficient materials. The constructed building will be added to the inventory, and inventory slot checking should not be necessary as there will be an open material slot after the building is successfully constructed. The building will be placed in an empty inventory slot.
8.  Makan
    - Roles: All roles
    - Description: Used to eat food according to the specified rules. First, display the storage according to the PRINT_STORAGE command. Then, the program will accept input in the form of a storage slot to be used as food. If the selected slot is valid food, it will become empty.
9.  Memberi Pangan
    - Roles: Rancher
    - Description: Used to feed livestock owned by the rancher. The types of food that can be accepted by each animal and the effects of feeding can be checked in the Ranching section. First, the program will display the ranch owned by the rancher. Then, display the storage of the rancher.
10. Membeli
    - Roles: All roles
    - Description: Used to buy items from the store. All items available in the store can be purchased as described above. The mayor cannot buy buildings. Each purchased item will occupy one slot in storage. If the storage is full, buying will not be possible. Buying also reduces the buyer's money. If the money is insufficient, buying cannot be done. All items in the store have a finite quantity, except for plants and animals.
11. Menjual
    - Roles: All roles
    - Description: Used to sell items owned in storage to the store. Farmers and ranchers cannot sell buildings. Selling multiple items at once will increase the quantity of those items in the store, except for plants and animals, which are infinite in quantity. If the storage is empty, selling cannot be done. The seller's money will increase immediately according to the selling price.
12. Memanen
    - Roles: Farmer, Rancher
    - Description: Used to harvest products from crops. Validate whether the user can harvest. First, display the field according to the PRINT_FIELD command. Then, display which types of crops are ready to be harvested along with how many tiles are ready to be harvested for each crop type.
13. Muat
    - Roles: All players
    - Description: Load can only be done at the beginning of the game to load the program state from a file. The loaded state includes the state of all players and the list of items available in the store. For inventory loading, it is free to place inventory items in available slots.
14. Simpan
    - Roles: All players
    - Description: Save can be done to save the entire state of players and the shop into a file. If the file does not exist, a new file will be created. If the folder does not exist, an error message will be displayed.
15. Tambah Pemain
    - Roles: Mayor
    - Description: The mayor can add players. Every time a player is added, the mayor needs to provide assistance of 50 gulden. The mayor can only add farmers and ranchers. If there is not enough money, the mayor cannot add players. Player names must be unique.


<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- CONTACT -->
## Contact

Project Link: [https://github.com/ValentinoTriadi/Tubes1_OOP](https://github.com/ValentinoTriadi/Tubes1_OOP)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [Maulvi Ziadinda Maulana](https://github.com/maulvi-zm)
* [Auralea Alvinia Syaikha](https://github.com/auraleaas)
* [Muhammad Fauzan Azhim](https://github.com/fauzanazz)
* [Muhammad Davis Adhipramana](https://github.com/Loxenary)
* [Valentino Chryslie Triadi](https://github.com/ValentinoTriadi)
<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/fauzanazz/IF2110_TB_03_B.svg?style=for-the-badge
[contributors-url]: https://github.com/ValentinoTriadi/Tubes1_OOP/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/fauzanazz/IF2110_TB_03_B.svg?style=for-the-badge
[forks-url]: https://github.com/ValentinoTriadi/Tubes1_OOP/network/members
[stars-shield]: https://img.shields.io/github/stars/fauzanazz/IF2110_TB_03_B.svg?style=for-the-badge
[stars-url]: https://github.com/ValentinoTriadi/Tubes1_OOP/stargazers
[issues-shield]: https://img.shields.io/github/issues/fauzanazz/IF2110_TB_03_B.svg?style=for-the-badge
[issues-url]: https://github.com/ValentinoTriadi/Tubes1_OOP/issues
