#ifndef EX2_PIECE_H
#define EX2_PIECE_H
#define WHITE_PLAYER 0
#define BLACK_PLAYER 1

#include <string>
#include <utility>
using std::string;

/**
 * Class Represent a piece in chess game.
 * Every piece in the game has position in x and y axis, his type, player he belong to and special
 * unicode that print symbol of the piece to screen.
 * Some of the pieces in the game need to remember if they moved already or not- like rook and king
 * (e.g. if they moved they can't make castling).
 */
class Piece
{
private:
    int _x, _y, _player;
    string _unicode, _pieceType;

public:
    /**
     * Constructor
     * @param xPos piece x axis number (row number in table).
     * @param yPos piece y axis number (column number in table).
     * @param player represent to who player the piece belong (0 if white, 1 if to the black).
     * @param unicode unicode that represent the type of piece.
     * @param someType type of piece.
     */
    Piece (int xPos, int yPos, int player, string unicode, string someType):
            _x(xPos), _y(yPos), _player(player), _unicode(unicode), _pieceType(someType){};
    /**
     * Destructor
     */
    virtual ~Piece() = default;

    /**
	* Access method for the xPos.
	* @return The xPos value
    */
    int getX() const;

    /**
	* Access method for the yPos.
	* @return The yPos value
    */
    int getY() const;

    /**
	* Access method for the player.
	* @return The player value (0 if white, 1 if black)
    */
    int getPlayer() const;

    /**
	* Access method for the unicode.
	* @return The unicode value
    */
    const string getUnicode() const;

    /**
	* Access method for the type.
	* @return The unicode value
    */
    const string getType() const;

    /**
     * Setter for new x and y positions.
     * @param x new x position.
     * @param y new y position.
     */
    void setCoordinates(int x, int y);

    /**
     * Check if the wanted moving is match the rules of the specific piece.
     * @param x new x position.
     * @param y new y position.
     * @return true if move match the rules of piece, else false
     */
    virtual bool move(int x, int y) const;

    /**
     * Check if piece moved before.
     * @return true if the piece moved already, else false
     */
    virtual bool movedBefore() const;

    /**
     * Setter the flag to true if piece moved.
     */
    virtual void setMoved();
};


#endif //EX2_PIECE_H
