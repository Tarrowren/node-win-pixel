const addon = require("../build/Release/node-win-pixel.node");

export type RGB = {
    r: number;
    g: number;
    b: number;
};

export class Pixel extends addon.Pixel {
    getPixel(x: number, y: number): RGB {
        return super.getPixel(x, y);
    }
}
