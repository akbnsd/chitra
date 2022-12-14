// This file is a part of  chitra (चित्र)
// Copyright (C) 2022  akshay bansod <aksh.bansod@yahoo.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.


#ifndef TEXTURE_HPP
#define TEXTURE_HPP

struct AVFrame;

// v-memory loaded image
struct texture
{
    texture(){};
    texture(AVFrame* frm) { operator=(frm); };

    AVFrame* operator=(AVFrame* frm);

    void load();

    bool isYUV() { return YUV;};
    ~texture();

    unsigned int texId=0, uvTexId=0, width=0, height=0, fmt=-1;
    unsigned char** data=0;
private:
    unsigned int currentHeight, currentWidth, currentFmt=-1;
    bool YUV=false;
};


#endif // TEXTURE_HPP
