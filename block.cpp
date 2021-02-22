#include "block.h"
#include <cmath>
#include <iostream>

int Block::width() const
{
/* your code here */
    return data.size();
}

int Block::height() const
{
/* your code here */
    return data.at(0).size();
}

void Block::render(PNG &im, int column, int row) const
{
/* your code here */
    for(int c = column; c < column + width(); c++){
        for(int r = row; r <  row + height(); r++) {
            * im.getPixel(c,r) = data.at(c-column).at(r-row);
        }
    }
}

void Block::build(PNG &im, int column, int row, int width, int height)
{
    /* your code here */
    for (int c = column; c < column + width; c++) {
        vector <HSLAPixel> col;
        for (int r = row; r < row + height; r++) {
            col.push_back(* im.getPixel(c, r)); 
        }
        data.push_back(col);
    }
}

void Block::flip()
{
/* your code here */
    for(unsigned col = 0; col < data.size(); col++) {
        reverse(data.at(col).begin(), data.at(col).end());
    }
}
