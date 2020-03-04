declare module "node-win-pixel" {
    class Pixel {
        getPixel(x: number, y: number): RGB;
    }

    namespace Pixel {
        interface RGB {
            r: number;
            g: number;
            b: number;
        }
    }

    export = Pixel;
}
