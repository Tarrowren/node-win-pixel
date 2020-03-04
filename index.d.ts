declare module "node-win-pixel" {
    interface RGB {
        r: number;
        g: number;
        b: number;
    }

    class Pixel {
        getPixel(x: number, y: number): RGB;
    }
}
