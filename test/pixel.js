const assert = require("chai").assert;
const { Pixel } = require("../out");

describe("node-win-pixel", function() {
    let pixel;

    this.beforeEach(function() {
        pixel = new Pixel();
    });

    describe(".getPixel", function() {
        it("throws an exception when argument range error", function() {
            assert.throws(function() {
                return pixel.getPixel(-1, -1);
            }, /invalid value/);
        });

        it("throws an exception when argument type error", function() {
            assert.throws(function() {
                return pixel.getPixel("x", "y");
            }, /the wrong type of argument/);
        });

        it("return type object", function() {
            assert.typeOf(pixel.getPixel(0, 0), "object");
        });
    });
});
