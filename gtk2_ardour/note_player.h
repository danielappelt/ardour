/*
 * Copyright (C) 2010-2017 Paul Davis <paul@linuxaudiosystems.com>
 * Copyright (C) 2011-2015 David Robillard <d@drobilla.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __gtk2_ardour_note_player_h__
#define __gtk2_ardour_note_player_h__

#include <memory>
#include <vector>

#include <sigc++/trackable.h>

#include "evoral/Note.h"

namespace Temporal {
	class Beats;
}

namespace ARDOUR {
	class MidiTrack;
}

class NotePlayer : public sigc::trackable {
public:
	typedef Evoral::Note<Temporal::Beats> NoteType;

	NotePlayer (std::shared_ptr<ARDOUR::MidiTrack>);
	~NotePlayer ();

	void add (std::shared_ptr<NoteType>);
	void play ();

private:
	void on ();
	void off ();
	static bool _off (NotePlayer*);
	typedef std::vector< std::shared_ptr<NoteType> > Notes;

	std::shared_ptr<ARDOUR::MidiTrack> track;
	Notes notes;
};

#endif /* __gtk2_ardour_note_player_h__ */
