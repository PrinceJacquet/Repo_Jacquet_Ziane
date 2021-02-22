#include "Cell.h"
#include <iostream>

Cell::Cell()
{
    _Mine = false;
    _Discovered = false;
    _Neighbours = 0;
}
Cell::~Cell()
{

}
void Cell::addMine(bool mine) /* addMine take as arg a boolean : "mine" and set the object attributes : "_Mine" */
{
    _Mine = mine;
}
int Cell::getNeighbours() /* getNeighbours set the object attributes : "_Neighbours"  to the new _Neighbours count*/
{
    
    return _Neighbours ;
}
void Cell::getNeighbours(std::vector<std::vector<Cell>> &grid, int x, int y)
{
    _Neighbours = 0;
    if (_Mine)
        return;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (x + i >= 0 && y + j >= 0 && x + i < grid.size() && y + j < grid[x + i].size())
            {
                if (grid[x + i][y + j].isAMine())
                    _Neighbours++;
            }
        }
    }
}
bool Cell::isDiscovered() /*very over complicated way to return _Discovered xD */
{
    if (_Discovered == true)
    {
        return true;
    }
    if (_Discovered == false)
    {
        return false;
    }
    else 
        return false;
}
/* // this just doesnt compile : out of my cpp skills scope xD
// and every things works fine without it : it's not even use in the program 
// I dont know where this is from actually

void Cell::isDiscovered(bool setDiscoveredStatus)
{
    if (setDiscoveredStatus == true)
    {
        _Discovered = true;
    }
    if (setDiscoveredStatus == false)
    {
        _Discovered = false;
    }
}
*/
bool Cell::isAMine() /*over complicated way to return _Mine (￣▽￣*)ゞ */
{
    if (_Mine == true)
    {
        return true;
    }
    if (_Mine == false)
    {
        return false ;
    } 
    else 
        return false;   
}
bool Cell::discover(std::vector<std::vector<Cell>> &grid, int x, int y)
{
    if (isAMine())
        return true;
    _Discovered = true;
    if (hasNeighbours())
        return false;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if ((x + i >= 0) && (y + j >= 0) && (x + i < grid.size()) && (y + j < grid[x + i].size()))
            {
                if (!grid[x + i][y + j].isAMine() && !grid[x + i][y + j].isDiscovered())
                    grid[x + i][y + j].discover(grid, x + i, y + j);
            }
        }
    }
    return false;
}
bool Cell::hasNeighbours() /*return boolean value (true) if cell has one or more neighboors with a mine*/
{
    /* good readability <(￣︶￣)> */
    if (_Neighbours > 0)
    {
        return true;
    }
    if (_Neighbours == 0)
    {
        return false;
    }
    else 
        return false;
}
bool Cell::isFlagged()
{
    return _Flag; // hehehe ! I got tired of writing 6 lines for just a return xD
}
void Cell::flag()
{
    _Flag = not _Flag; // toggle flag value
}